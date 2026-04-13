#include "server.h"
#include <QJsonDocument>
#include <QDebug>
#include "database.h"

ChatServer::ChatServer(QObject *parent)
    : QTcpServer(parent)
{
}

bool ChatServer::start(quint16 port)
{
    if(listen(QHostAddress::Any, port)) {
        emit logMessage("✅ Server started on port " + QString::number(port));
        return true;
    }
    emit logMessage("❌ Failed to start server: " + errorString());
    return false;
}

void ChatServer::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket *socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);

    // 🔴 ИСПРАВИТЬ — передать this
    ClientHandler *handler = new ClientHandler(socket, this, this);

    connect(handler, &ClientHandler::newMessage, this, [this](const ChatMessage &msg) {
        if(msg.to.isEmpty()) {
            for(auto client : m_clients) {
                client->sendMessage(msg);
            }
        } else {
            if(m_clients.contains(msg.to)) {
                m_clients[msg.to]->sendMessage(msg);
            }
        }
    });

    connect(handler, &ClientHandler::clientReady, this, [this, handler](const QString &username) {
        m_clients[username] = handler;
        emit logMessage("👤 User logged in: " + username);

        ChatMessage statusMsg;
        statusMsg.type = MsgType::Status;
        statusMsg.content = "online";
        statusMsg.from = username;

        for(auto client : m_clients) {
            client->sendMessage(statusMsg);
        }
    });

    connect(handler, &ClientHandler::clientDisconnected, this, [this](const QString &username) {
        m_clients.remove(username);
        emit logMessage("👤 User logged out: " + username);

        ChatMessage statusMsg;
        statusMsg.type = MsgType::Status;
        statusMsg.content = "offline";
        statusMsg.from = username;

        for(auto client : m_clients) {
            client->sendMessage(statusMsg);
        }
    });
}
