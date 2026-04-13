#include "client.h"
#include <QJsonDocument>
#include <QDebug>

ChatClient::ChatClient(QObject *parent)
    : QObject(parent)
    , m_socket(new QTcpSocket(this))
    , m_authenticated(false)
{
    connect(m_socket, &QTcpSocket::connected, this, &ChatClient::onConnected);
    connect(m_socket, &QTcpSocket::readyRead, this, &ChatClient::onReadyRead);
    connect(m_socket, &QTcpSocket::disconnected, this, &ChatClient::onDisconnected);
}

void ChatClient::connectToServer(const QString &host, quint16 port)
{
    m_socket->connectToHost(host, port);
}

void ChatClient::requestUserList()
{
    if(!m_authenticated) {
        qDebug() << "Not authenticated. Please login first.";
        return;
    }

    ChatMessage msg;
    msg.type = MsgType::UserList;
    msg.from = m_username;
    send(msg);
}

void ChatClient::login(const QString &username, const QString &password)
{
    m_username = username;
    ChatMessage msg;
    msg.type = MsgType::Login;
    msg.from = username;
    msg.content = password;
    send(msg);
}

void ChatClient::registerUser(const QString &username, const QString &password)
{
    ChatMessage msg;
    msg.type = MsgType::Register;
    msg.from = username;
    msg.content = password;
    send(msg);
}
void ChatClient::requestHistory(const QString &withUser)
{
    if(!m_authenticated) return;

    ChatMessage msg;
    msg.type = MsgType::History;
    msg.from = m_username;
    msg.content = withUser;
    send(msg);
}


void ChatClient::sendMessage(const QString &to, const QString &content)
{
    if(!m_authenticated) {
        qDebug() << "Not authenticated";
        return;
    }

    ChatMessage msg;
    msg.type = MsgType::TextMessage;
    msg.from = m_username;
    msg.to = to;
    msg.content = content;
    send(msg);
}

void ChatClient::logout()
{
    ChatMessage msg;
    msg.type = MsgType::Logout;
    msg.from = m_username;
    send(msg);
    m_socket->disconnectFromHost();
}

void ChatClient::send(const ChatMessage &msg)
{
    QJsonDocument doc(msg.toJson());
    QByteArray data = doc.toJson(QJsonDocument::Compact) + "\n";
    qDebug() << "[CLIENT] Sending:" << data;
    m_socket->write(data);
}

void ChatClient::onConnected()
{
    emit connected();
}

void ChatClient::onReadyRead()
{
    QByteArray newData = m_socket->readAll();
    qDebug() << "[CLIENT] RAW DATA RECEIVED:" << newData;

    m_buffer.append(newData);

    while(m_buffer.contains('\n')) {
        int pos = m_buffer.indexOf('\n');
        QByteArray data = m_buffer.left(pos);
        m_buffer.remove(0, pos + 1);

        QJsonDocument doc = QJsonDocument::fromJson(data);
        if(!doc.isNull()) {
            ChatMessage msg = ChatMessage::fromJson(doc.object());
            qDebug() << "[CLIENT] Message type:" << static_cast<int>(msg.type);

            if(msg.type == MsgType::LoginOK) {
                m_authenticated = true;
                qDebug() << "✅ " << msg.content;
            } else if(msg.type == MsgType::LoginFailed) {
                emit errorOccurred(msg.content);
            } else if(msg.type == MsgType::RegisterOK) {
                qDebug() << "✅ " << msg.content;
            } else if(msg.type == MsgType::RegisterFailed) {
                qDebug() << "❌ " << msg.content;
            } else if(msg.type == MsgType::UserList) {
                // 🔴 ОБРАБОТКА СПИСКА ПОЛЬЗОВАТЕЛЕЙ
                // Формат: "user1:online,user2:offline,user3:online"
                QStringList userStatuses = msg.content.split(",", Qt::SkipEmptyParts);

                QMap<QString, bool> users;
                for(const QString &userStatus : userStatuses) {
                    QStringList parts = userStatus.split(":");
                    if(parts.size() == 2) {
                        users[parts[0]] = (parts[1] == "online");
                    }
                }

                emit userListReceived(users);
            } else if(msg.type == MsgType::TextMessage) {
                if(msg.to.isEmpty()) {
                    qDebug() << "📢 [BROADCAST from " << msg.from << "]: " << msg.content;
                } else {
                    qDebug() << "💬 [" << msg.from << " → " << msg.to << "]: " << msg.content;
                }
            } else if(msg.type == MsgType::Status) {
                qDebug() << "📡 User " << msg.from << " is " << msg.content;
            }

            emit messageReceived(msg);
        }
    }
}

void ChatClient::onDisconnected()
{
    m_authenticated = false;
    emit disconnected();
}
