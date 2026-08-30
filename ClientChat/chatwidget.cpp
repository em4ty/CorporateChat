#include "chatwidget.h"
#include "ui_chatwidget.h"
#include <QDateTime>
#include <QScrollBar>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>
#include <QBuffer>
#include <QWidget>
#include "utils.h"


ChatWidget::ChatWidget(const QString &myUsername,
                       const QString &peerUsername,
                       ChatClient *client,
                       QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatWidget)
    , m_client(client)
    , m_myUsername(myUsername)
    , m_peerUsername(peerUsername)
{

    ui->setupUi(this);
    ui->chatLayout->setAlignment(Qt::AlignTop);
    ui->scrollAreaWidgetContents->setStyleSheet("background-color: #14141f;");
    connect(ui->sendButton, &QPushButton::clicked, this, &ChatWidget::onSendClicked);
    connect(ui->messageEdit, &QLineEdit::returnPressed, this, &ChatWidget::onSendClicked);
    connect(m_client, &ChatClient::messageReceived, this, &ChatWidget::onMessageReceived);
    connect(m_client, &ChatClient::historyReceived, this, &ChatWidget::onHistoryReceived);
    connect(ui->attachButton, &QPushButton::clicked, this, &ChatWidget::onAttachClicked);
    m_client->requestHistory(m_peerUsername);
    ui->chatPartnerLabel->setText(m_peerUsername);
    updateAvatar();
}

void ChatWidget::sendFileToServer(const QString &filePath){
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл");
        return;
    }
    QByteArray fileData = file.readAll();
    QString filename = QFileInfo(file).fileName();
    file.close();

    const int MAX_SIZE = 50 * 1024 * 1024; // 50 МБ
    if (fileData.size() > MAX_SIZE) {
        QMessageBox::warning(this, "Ошибка", "Файл больше 50 МБ");
        return;
    }
    // Формируем пакет: [имя файла][размер][данные]
    QByteArray packet;
    QDataStream stream(&packet, QIODevice::WriteOnly);
    stream << filename << (quint64)fileData.size() << fileData;

    // Отправляем на файловый сервер
    QTcpSocket *socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::connected, this, [socket, packet, filename, this]() {
        socket->write(packet);
        socket->disconnectFromHost();
        addMessage("📎 Файл отправлен: " + filename, true);
    });

    connect(socket, &QTcpSocket::errorOccurred, this, [this](QAbstractSocket::SocketError) {
        QMessageBox::warning(this, "Ошибка", "Не удалось подключиться к файловому серверу");
    });

    // Файловый сервер запущен на том же хосте, порт 12346
    socket->connectToHost("127.0.0.1", 12346);
}

void ChatWidget::updateAvatar()
{
    if (!ui->avatarLabel) return;

    QPixmap avatar = generateAvatar(m_peerUsername, 40);
    ui->avatarLabel->setPixmap(avatar.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->avatarLabel->setStyleSheet("border-radius: 20px; background: transparent;");
}
void ChatWidget::onHistoryReceived(const ChatMessage &msg)
{
    if (msg.type != MsgType::History) return;

    QStringList historyParts = msg.content.split('|', Qt::SkipEmptyParts);
    for (const QString &part : historyParts) {
        QStringList fields = part.split(':');
        if (fields.size() >= 3) {
            QString from = fields[0];
            QString content = fields[2];
            if (from == m_myUsername) {
                addMessage(content, true);
            } else if (from == m_peerUsername) {
                addMessage(content, false);
            }
        }
    }
}
void ChatWidget::updateStatus(bool isOnline){
    QString statusText = isOnline ? "●" : "○";
    QString statusColor = isOnline ? "#4caf50" : "#666666";
    ui->statusIndicator->setText(statusText);
    ui->statusIndicator->setStyleSheet(QString("color: %1; padding-right: 16px;").arg(statusColor));
}
void ChatWidget::onAttachClicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Выберите файл");
    if (filePath.isEmpty()) return;

    sendFileToServer(filePath);  // ← новый способ
}

void ChatWidget::onSendClicked()
{
    QString text = ui->messageEdit->text().trimmed();
    if (text.isEmpty()) return;

    qDebug() << "=== Sending message ===";
    qDebug() << "From (me):" << m_myUsername;
    qDebug() << "To:" << m_peerUsername;

    m_client->sendMessage(m_peerUsername, text);
    addMessage(text, true);
    ui->messageEdit->clear();
}
void ChatWidget::downloadFile(const QString &fileId)
{
    qDebug() << "[Client] downloadFile called with ID:" << fileId;
    ChatMessage request;
    request.type = MsgType::FileRequest;
    request.fileId = fileId;
    request.from = m_myUsername;
    request.to = m_peerUsername;
    m_client->send(request);
}
void ChatWidget::addFileMessage(const QString &filename, const QString &fileId)
{
    // Создаём HTML-ссылку
    QString displayText = QString("<a href=\"file://%1\" style=\"color: #9146ff; text-decoration: underline;\">📎 %1</a>")
                              .arg(filename);

    QLabel *label = new QLabel(displayText);
    label->setOpenExternalLinks(false); // не открываем в браузере, обрабатываем сами
    label->setTextFormat(Qt::RichText); // включаем HTML
    label->setCursor(Qt::PointingHandCursor);
    label->setWordWrap(true);

    // Подключаем сигнал на клик
    connect(label, &QLabel::linkActivated, this, [this, fileId, filename]() {
        qDebug() << "[Client] File clicked:" << filename << "ID:" << fileId;
        downloadFile(fileId);
    });

    // Добавляем в чат
    QFrame *frame = new QFrame;
    frame->setStyleSheet("background: transparent; padding: 4px;");
    QVBoxLayout *layout = new QVBoxLayout(frame);
    layout->addWidget(label);
    layout->setContentsMargins(0, 0, 0, 0);

    ui->chatLayout->addWidget(frame);
    ui->chatScrollArea->verticalScrollBar()->setValue(
        ui->chatScrollArea->verticalScrollBar()->maximum()
        );
}

void ChatWidget::onMessageReceived(const ChatMessage &msg)
{
    // ===== Файл получен (ответ на запрос) =====
    if (msg.type == MsgType::FileResponse) {
        QString filename = msg.fileName;
        QByteArray fileData = QByteArray::fromBase64(msg.content.toUtf8());

        QDir dir;
        if (!dir.exists("downloads")) dir.mkdir("downloads");

        QString filePath = "downloads/" + filename;
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly)) {
            file.write(fileData);
            file.close();
            addMessage("📂 Файл сохранён: " + filename + " (в папке downloads)", false);
        } else {
            addMessage("❌ Ошибка сохранения файла", false);
        }
        return;
    }

    // ===== Уведомление о новом файле =====
    if (msg.type == MsgType::FileInfo) {
        qDebug() << "[Client] FileInfo received! Name:" << msg.fileName << "ID:" << msg.fileId;
        addFileMessage(msg.fileName, msg.fileId);
        return;
    }

    // ===== Текстовые сообщения =====
    if (msg.type != MsgType::TextMessage) return;

    qDebug() << "=== Message received ===";
    qDebug() << "From:" << msg.from;
    qDebug() << "To:" << msg.to;

    if (msg.from == m_peerUsername && msg.to == m_myUsername) {
        addMessage(msg.content, false);
    }
}

void ChatWidget::addMessage(const QString &content, bool isMine, const QString &time)
{
    if (content.isEmpty()) return;

    QFrame *frame = new QFrame;
    frame->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);

    QString bgColor = isMine ? "#9146ff" : "#2a2a3e";
    QString textColor = isMine ? "white" : "#e0e0e0";
    int maxWidth = 400;

    frame->setStyleSheet(QString(
                             "QFrame {"
                             "    background-color: %1;"
                             "    border-radius: 14px;"
                             "    padding: 4px 10px;"
                             "    margin: 2px 0;"
                             "    max-width: %2px;"
                             "}"
                             ).arg(bgColor).arg(maxWidth));

    // Текст
    QLabel *textLabel = new QLabel(content);
    textLabel->setWordWrap(true);
    textLabel->setStyleSheet(QString(
                                 "QLabel {"
                                 "    color: %1;"
                                 "    font-size: 18px;"
                                 "    background: transparent;"
                                 "    margin: 0;"
                                 "    padding: 0;"
                                 "}"
                                 ).arg(textColor));

    // Время
    QString timeStr = time.isEmpty() ? QDateTime::currentDateTime().toString("hh:mm") : time;
    QLabel *timeLabel = new QLabel(timeStr);
    timeLabel->setStyleSheet(QString(
                                 "QLabel {"
                                 "    color: %1;"
                                 "    font-size: 9px;"
                                 "    background: transparent;"
                                 "    opacity: 0.6;"
                                 "    margin: 0;"
                                 "    padding: 0;"
                                 "}"
                                 ).arg(isMine ? "#d0b0ff" : "#888888"));

    // Layout
    QVBoxLayout *msgLayout = new QVBoxLayout(frame);
    msgLayout->addWidget(textLabel);
    msgLayout->addWidget(timeLabel, 0, Qt::AlignRight);
    msgLayout->setSpacing(0);
    msgLayout->setContentsMargins(0, 0, 0, 0);

    Qt::Alignment align = isMine ? Qt::AlignRight : Qt::AlignLeft;
    ui->chatLayout->addWidget(frame, 0, align);

    QScrollBar *vScroll = ui->chatScrollArea->verticalScrollBar();
    vScroll->setValue(vScroll->maximum());
}
ChatWidget::~ChatWidget()
{
    delete ui;
}
