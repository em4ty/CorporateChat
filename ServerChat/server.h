#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include "message.h"
#include "clienthandler.h"

class ChatServer : public QTcpServer
{
    Q_OBJECT

public:
    explicit ChatServer(QObject *parent = nullptr);
    bool start(quint16 port);

    // 🔴 ДОБАВИТЬ МЕТОД
    QStringList getOnlineUsers() const { return m_clients.keys(); }

signals:
    void logMessage(const QString &msg);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private:
    QMap<QString, ClientHandler*> m_clients;
};

#endif
