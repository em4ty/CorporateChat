#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chatwidget.h"
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include "utils.h"
#include <QMouseEvent>

MainWindow::MainWindow(const QString &username, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_username(username)
    , m_client(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("Чат - " + username);

    connect(ui->logoutButton, &QPushButton::clicked, this, &MainWindow::onLogout);
    connect(ui->userList, &QListWidget::itemClicked, this, &MainWindow::onUserSelected);
    connect(m_client, &ChatClient::statusReceived, this, &MainWindow::onStatusReceived);
    // Таймер для обновления списка пользователей
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::requestUserList);
    timer->start(5000);
    // Убираем стандартный заголовок окна
    setWindowFlags(Qt::FramelessWindowHint);

    // Подключаем кнопки управления
    connect(ui->minimizeButton, &QPushButton::clicked, this, &QMainWindow::showMinimized);
    connect(ui->maximizeButton, &QPushButton::clicked, this, [this]() {
        if (isMaximized()) {
            showNormal();
            ui->maximizeButton->setText("□");
        } else {
            showMaximized();
            ui->maximizeButton->setText("❐");
        }
    });
    connect(ui->closeButton, &QPushButton::clicked, this, &QMainWindow::close);

    // Устанавливаем аватарку текущего пользователя (внизу слева)
    QPixmap avatar = generateAvatar(m_username, 40);
    ui->userAvatarLabel->setPixmap(avatar.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->userAvatarLabel->setStyleSheet("border-radius: 20px; background: transparent;");

    // Устанавливаем имя пользователя
    ui->usernameLabel->setText(m_username);

    QFont emptyFont("Segoe UI", 18, QFont::Bold); // Шрифт: Segoe UI, размер 18, жирный
    ui->emptyLabel->setFont(emptyFont);           // Устанавливаем шрифт
    ui->emptyLabel->setStyleSheet("color: #e0e0e0;");
}
void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_dragPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
        event->accept();
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPosition().toPoint() - m_dragPosition);
        event->accept();
    }
}
void MainWindow::onStatusReceived(const QString &username, bool isOnline)
{
    // Обновляем список контактов
    for (int i = 0; i < ui->userList->count(); ++i) {
        QListWidgetItem *item = ui->userList->item(i);
        if (item->data(Qt::UserRole).toString() == username) {
            item->setText(username); //(isOnline ? "🟢 " : "⚪ ") +
            item->setForeground(isOnline ? QBrush(QColor(0, 128, 0)) : QBrush(QColor(128, 128, 128)));
            break;
        }
    }

    // Если чат с этим пользователем открыт — обновляем индикатор в заголовке
    if (m_chatWidgets.contains(username)) {
        ChatWidget *chat = m_chatWidgets[username];
        if (ui->chatStack->currentWidget() == chat) {
            chat->updateStatus(isOnline);
        }
    }
}
void MainWindow::setClient(ChatClient *client)
{
    if(!client) return;

    m_client = client;
    m_client->setParent(this);

    connect(m_client, &ChatClient::messageReceived, this, &MainWindow::onMessageReceived);
    connect(m_client, &ChatClient::userListReceived, this, &MainWindow::updateUserList);

    m_client->setUsername(m_username);
    m_client->setAuthenticated(true);

    QTimer::singleShot(500, this, &MainWindow::requestUserList);
}

void MainWindow::requestUserList()
{
    if(!m_client) return;
    m_client->requestUserList();
}

void MainWindow::updateUserList(const QMap<QString, bool> &users)
{
    ui->userList->clear();

    for (auto it = users.begin(); it != users.end(); ++it) {
        QString username = it.key();
        bool isOnline = it.value();

        // Генерируем аватарку
        QPixmap avatar = generateAvatar(username, 32); // 32px для списка
        QIcon icon(avatar);

        QListWidgetItem *item = new QListWidgetItem(icon,  username);
        item->setData(Qt::UserRole, username);
        ui->userList->addItem(item);
    }
}

void MainWindow::onUserSelected(QListWidgetItem *item)
{
    QString selected = item->data(Qt::UserRole).toString();
    if (selected.isEmpty()) return;

    // Проверяем, есть ли уже виджет чата
    if (!m_chatWidgets.contains(selected)) {
        ChatWidget *chat = new ChatWidget(m_username, selected, m_client, this);
        m_chatWidgets[selected] = chat;
        ui->chatStack->addWidget(chat);
    }

    ui->chatStack->setCurrentWidget(m_chatWidgets[selected]);

    // Убираем индикатор непрочитанного, если был
    for (int i = 0; i < ui->userList->count(); ++i) {
        QListWidgetItem *userItem = ui->userList->item(i);
        if (userItem->data(Qt::UserRole).toString() == selected) {
            bool isOnline = userItem->text().startsWith("🟢");
            userItem->setText(selected);
            break;
        }
    }

    // 👇 НОВОЕ: устанавливаем статус в заголовке чата
    bool isOnline = false;
    for (int i = 0; i < ui->userList->count(); ++i) {
        QListWidgetItem *userItem = ui->userList->item(i);
        if (userItem->data(Qt::UserRole).toString() == selected) {
            isOnline = userItem->text().startsWith("🟢");
            break;
        }
    }
    m_chatWidgets[selected]->updateStatus(isOnline);
}

void MainWindow::onMessageReceived(const ChatMessage &msg)
{
    if (msg.type != MsgType::TextMessage) return;

    QString peer = (msg.from == m_username) ? msg.to : msg.from;

    if (!m_chatWidgets.contains(peer)) {
        ChatWidget *chat = new ChatWidget(m_username, peer, m_client, this);
        m_chatWidgets[peer] = chat;
        ui->chatStack->addWidget(chat);

        // Устанавливаем статус для нового чата
        bool isOnline = false;
        for (int i = 0; i < ui->userList->count(); ++i) {
            QListWidgetItem *userItem = ui->userList->item(i);
            if (userItem->data(Qt::UserRole).toString() == peer) {
                isOnline = userItem->text().startsWith("🟢");
                break;
            }
        }
        chat->updateStatus(isOnline);
    }

    // Индикатор непрочитанного
    if (ui->chatStack->currentWidget() != m_chatWidgets[peer]) {
        for (int i = 0; i < ui->userList->count(); ++i) {
            QListWidgetItem *item = ui->userList->item(i);
            if (item->data(Qt::UserRole).toString() == peer) {
                if (!item->text().startsWith("🔴")) {
                    item->setText("🔴 " + peer);
                }
                break;
            }
        }
    }
}

void MainWindow::onLogout()
{
    if(m_client) m_client->logout();
    close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
