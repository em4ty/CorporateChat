#include "chatwidget.h"
#include "ui_chatwidget.h"
#include <QDateTime>
#include <QListWidgetItem>

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

    connect(ui->sendButton, &QPushButton::clicked, this, &ChatWidget::onSendClicked);
    connect(ui->messageEdit, &QLineEdit::returnPressed, this, &ChatWidget::onSendClicked);
    connect(m_client, &ChatClient::messageReceived, this, &ChatWidget::onMessageReceived);
    connect(m_client, &ChatClient::historyReceived, this, &ChatWidget::onHistoryReceived);  // 🔴 НОВЫЙ

    // 🔴 ЗАГРУЖАЕМ ИСТОРИЮ
    m_client->requestHistory(m_peerUsername);
}

void ChatWidget::onHistoryReceived(const QList<ChatMessage> &history)
{
    for(const ChatMessage &msg : history) {
        if(msg.from == m_myUsername) {
            addMyMessage(msg.content);
        } else if(msg.from == m_peerUsername) {
            addOtherMessage(msg.from, msg.content);
        }
    }
}

void ChatWidget::onSendClicked()
{
    QString text = ui->messageEdit->text().trimmed();
    if(text.isEmpty()) return;

    qDebug() << "=== Sending message ===";
    qDebug() << "From (me):" << m_myUsername;
    qDebug() << "To:" << m_peerUsername;

    m_client->sendMessage(m_peerUsername, text);
    addMyMessage(text);
    ui->messageEdit->clear();
}

void ChatWidget::onMessageReceived(const ChatMessage &msg)
{
    if(msg.type != MsgType::TextMessage) return;

    qDebug() << "=== Message received ===";
    qDebug() << "From:" << msg.from;
    qDebug() << "To:" << msg.to;

    // Проверяем, что сообщение для этого чата
    if(msg.from == m_peerUsername && msg.to == m_myUsername) {
        addOtherMessage(msg.from, msg.content);
    }
}

void ChatWidget::addMyMessage(const QString &content)
{
    QString time = QDateTime::currentDateTime().toString("hh:mm:ss");

    QListWidgetItem *item = new QListWidgetItem();
    item->setTextAlignment(Qt::AlignRight);
    item->setText(QString("%1\n%2").arg(content).arg(time));
    item->setBackground(QColor(220, 248, 198)); // зелёный
    item->setForeground(QColor(0, 0, 0));

    ui->chatDisplay->addItem(item);
    ui->chatDisplay->scrollToBottom();
}

void ChatWidget::addOtherMessage(const QString &from, const QString &content)
{
    QString time = QDateTime::currentDateTime().toString("hh:mm:ss");

    QListWidgetItem *item = new QListWidgetItem();
    item->setTextAlignment(Qt::AlignLeft);
    item->setText(QString("%1:\n%2\n%3").arg(from).arg(content).arg(time));
    item->setBackground(QColor(240, 240, 240)); // серый
    item->setForeground(QColor(0, 0, 0));

    ui->chatDisplay->addItem(item);
    ui->chatDisplay->scrollToBottom();
}

ChatWidget::~ChatWidget()
{
    delete ui;
}
