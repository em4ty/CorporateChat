#include "clienthandler.h"
#include "server.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QSqlQuery>
#include <QCryptographicHash>
#include "database.h"

ClientHandler::ClientHandler(QTcpSocket *socket, ChatServer *server, QObject *parent)
    : QObject(parent)
    , m_socket(socket)
    , m_server(server)
    , m_authenticated(false)
{
    connect(m_socket, &QTcpSocket::readyRead, this, &ClientHandler::onReadyRead);
    connect(m_socket, &QTcpSocket::disconnected, this, &ClientHandler::onDisconnected);
}

ClientHandler::~ClientHandler()
{
    if(m_socket) {
        m_socket->deleteLater();
    }
}

void ClientHandler::onReadyRead()
{
    QByteArray data = m_socket->readAll();
    qDebug() << "[SERVER] Raw received:" << data;

    m_buffer.append(data);

    while(m_buffer.contains('\n')) {
        int pos = m_buffer.indexOf('\n');
        QByteArray line = m_buffer.left(pos);
        m_buffer.remove(0, pos + 1);

        QJsonDocument doc = QJsonDocument::fromJson(line);
        if(!doc.isNull()) {
            ChatMessage msg = ChatMessage::fromJson(doc.object());
            qDebug() << "[SERVER] Parsed type:" << static_cast<int>(msg.type);

            if(!m_authenticated) {
                if(msg.type == MsgType::Login) {
                    processLogin(msg);
                } else if(msg.type == MsgType::Register) {
                    processRegister(msg);
                } else {
                    sendError("Not authenticated");
                }
            } else {
                processTextMessage(msg);
            }
        }
    }
}

void ClientHandler::processLogin(const ChatMessage &msg)
{
    QString username = msg.from;
    QString password = msg.content;

    qDebug() << "[SERVER] Login attempt from:" << username;

    QString passwordHash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    if(Database::instance().checkUser(username, passwordHash)) {
        qDebug() << "[SERVER] Login SUCCESS for:" << username;

        m_authenticated = true;
        m_username = username;

        ChatMessage response;
        response.type = MsgType::LoginOK;
        response.content = "Welcome, " + username;
        response.to = username;

        qDebug() << "[SERVER] Sending LoginOK to:" << username;
        sendMessage(response);

        emit clientReady(username);
    } else {
        qDebug() << "[SERVER] Login FAILED for:" << username;
        sendError("Invalid username or password");
    }
}

void ClientHandler::processRegister(const ChatMessage &msg)
{
    QString username = msg.from;
    QString password = msg.content;

    qDebug() << "[SERVER] Register attempt from:" << username;

    QString passwordHash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    if(Database::instance().addUser(username, passwordHash)) {
        qDebug() << "[SERVER] Register SUCCESS for:" << username;

        ChatMessage response;
        response.type = MsgType::RegisterOK;
        response.content = "Registration successful! Please login.";
        response.to = username;
        sendMessage(response);
    } else {
        qDebug() << "[SERVER] Register FAILED for:" << username;
        sendError("Username already exists");
    }
}

void ClientHandler::processTextMessage(const ChatMessage &msg)
{
    if(msg.type == MsgType::History) {
        QString withUser = msg.content;
        qDebug() << "[SERVER] History requested by:" << m_username << "with:" << withUser;

        QList<ChatMessage> history = Database::instance().getMessages(m_username, withUser);

        ChatMessage response;
        response.type = MsgType::History;

        QStringList historyList;
        for(const ChatMessage &m : history) {
            historyList << QString("%1:%2:%3").arg(m.from).arg(m.to).arg(m.content);
        }
        response.content = historyList.join("|");
        response.to = m_username;
        sendMessage(response);
        return;
    }
    // 🔴 ОБРАБОТКА ЗАПРОСА СПИСКА ПОЛЬЗОВАТЕЛЕЙ (ВСЕХ, С СТАТУСАМИ)
    if(msg.type == MsgType::UserList) {
        qDebug() << "[SERVER] UserList requested by:" << m_username;

        ChatMessage response;
        response.type = MsgType::UserList;

        // 🔴 ПОЛУЧАЕМ ВСЕХ ПОЛЬЗОВАТЕЛЕЙ ИЗ БД
        QStringList allUsers = Database::instance().getAllUsers();
        QStringList onlineUsers = m_server->getOnlineUsers();

        QStringList userStatuses;
        for(const QString &user : allUsers) {
            if(user == m_username) continue;
            QString status = onlineUsers.contains(user) ? "online" : "offline";
            userStatuses << user + ":" + status;
        }

        response.content = userStatuses.join(",");
        response.to = m_username;
        sendMessage(response);
        return;
    }

    // 🔴 ОБРАБОТКА ВЫХОДА
    if(msg.type == MsgType::Logout) {
        qDebug() << "[SERVER] Logout from:" << m_username;
        m_socket->disconnectFromHost();
        return;
    }

    // Обычное текстовое сообщение
    ChatMessage newMsg = msg;
    newMsg.timestamp = QDateTime::currentDateTime();
    newMsg.from = m_username;

    // Сохраняем в БД
    Database::instance().saveMessage(newMsg);

    emit newMessage(newMsg);
}

void ClientHandler::sendMessage(const ChatMessage &msg)
{
    QJsonDocument doc(msg.toJson());
    QByteArray data = doc.toJson(QJsonDocument::Compact) + "\n";
    qDebug() << "[SERVER] Sending:" << data;
    m_socket->write(data);
}

void ClientHandler::sendError(const QString &error)
{
    ChatMessage msg;
    msg.type = MsgType::LoginFailed;
    msg.content = error;
    sendMessage(msg);
}

void ClientHandler::onDisconnected()
{
    if(m_authenticated) {
        emit clientDisconnected(m_username);
    }
    deleteLater();
}
