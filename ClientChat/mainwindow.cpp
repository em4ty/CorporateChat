#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chatwidget.h"
#include <QMessageBox>
#include <QTimer>
#include <QDebug>

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

    // Таймер для обновления списка пользователей
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::requestUserList);
    timer->start(5000);
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

    for(auto it = users.begin(); it != users.end(); ++it) {
        QString username = it.key();
        bool isOnline = it.value();

        QListWidgetItem *item;
        if(isOnline) {
            item = new QListWidgetItem("🟢 " + username);
            item->setForeground(QBrush(QColor(0, 128, 0))); // зелёный
        } else {
            item = new QListWidgetItem("⚪ " + username);
            item->setForeground(QBrush(QColor(128, 128, 128))); // серый
        }
        item->setData(Qt::UserRole, username);
        ui->userList->addItem(item);
    }
}

void MainWindow::onUserSelected(QListWidgetItem *item)
{
    QString selected = item->data(Qt::UserRole).toString();
    if(selected.isEmpty()) return;

    // Проверяем, есть ли уже виджет чата
    if(!m_chatWidgets.contains(selected)) {
        ChatWidget *chat = new ChatWidget(m_username, selected, m_client, this);
        m_chatWidgets[selected] = chat;
        ui->chatStack->addWidget(chat);
    }

    ui->chatStack->setCurrentWidget(m_chatWidgets[selected]);

    // Убираем индикатор непрочитанного, если был
    for(int i = 0; i < ui->userList->count(); ++i) {
        QListWidgetItem *userItem = ui->userList->item(i);
        if(userItem->data(Qt::UserRole).toString() == selected) {
            bool isOnline = (userItem->text().startsWith("🟢"));
            userItem->setText((isOnline ? "🟢 " : "⚪ ") + selected);
            break;
        }
    }
}

void MainWindow::onMessageReceived(const ChatMessage &msg)
{
    if(msg.type == MsgType::TextMessage) {
        QString peer = (msg.from == m_username) ? msg.to : msg.from;

        if(!m_chatWidgets.contains(peer)) {
            ChatWidget *chat = new ChatWidget(m_username, peer, m_client, this);
            m_chatWidgets[peer] = chat;
            ui->chatStack->addWidget(chat);
        }


        // Индикатор непрочитанного
        if(ui->chatStack->currentWidget() != m_chatWidgets[peer]) {
            for(int i = 0; i < ui->userList->count(); ++i) {
                QListWidgetItem *item = ui->userList->item(i);
                if(item->data(Qt::UserRole).toString() == peer) {
                    if(!item->text().startsWith("🔴")) {
                        item->setText("🔴 " + peer);
                    }
                    break;
                }
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
