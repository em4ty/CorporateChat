#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include <QTcpSocket>
#include <QTimer>
#include "message.h"

class ChatServer;  // forward declaration

class ClientHandler : public QObject
{
    Q_OBJECT

public:
    explicit ClientHandler(QTcpSocket *socket, ChatServer *server, QObject *parent = nullptr);
    ~ClientHandler();

    void sendMessage(const ChatMessage &msg);
    QString username() const { return m_username; }

signals:
    void newMessage(const ChatMessage &msg);
    void clientReady(const QString &username);
    void clientDisconnected(const QString &username);

private slots:
    void onReadyRead();
    void onDisconnected();

private:
    void processLogin(const ChatMessage &msg);
    void processRegister(const ChatMessage &msg);
    void processTextMessage(const ChatMessage &msg);
    void sendError(const QString &error);

private:
    QTcpSocket *m_socket;
    ChatServer *m_server;      // ← ДОБАВИТЬ
    QString m_username;
    bool m_authenticated;
    QByteArray m_buffer;
};

#endif
