#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QObject>
#include <QMap>
#include "message.h"

class ChatClient : public QObject
{
    Q_OBJECT

public:
    explicit ChatClient(QObject *parent = nullptr);

    void connectToServer(const QString &host, quint16 port);
    void login(const QString &username, const QString &password);
    void registerUser(const QString &username, const QString &password);
    void sendMessage(const QString &to, const QString &content);
    void logout();
    void requestUserList();
    void requestHistory(const QString &withUser);  // 🔴 НОВЫЙ МЕТОД

    void setUsername(const QString &username) { m_username = username; }
    void setAuthenticated(bool auth) { m_authenticated = auth; }
    bool isAuthenticated() const { return m_authenticated; }
    bool isConnected() const { return m_socket->state() == QAbstractSocket::ConnectedState; }

signals:
    void connected();
    void disconnected();
    void messageReceived(const ChatMessage &msg);
    void errorOccurred(const QString &error);
    void userListReceived(const QMap<QString, bool> &users);
    void historyReceived(const QList<ChatMessage> &history);  // 🔴 НОВЫЙ СИГНАЛ

private slots:
    void onReadyRead();
    void onConnected();
    void onDisconnected();

private:
    void send(const ChatMessage &msg);

private:
    QTcpSocket *m_socket;
    QByteArray m_buffer;
    QString m_username;
    bool m_authenticated;
};

#endif
