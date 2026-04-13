#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QList>
#include "message.h"

class Database
{
public:
    static Database& instance();

    bool init(const QString &path = "chat.db");
    bool addUser(const QString &username, const QString &passwordHash);
    bool checkUser(const QString &username, const QString &passwordHash);
    QStringList getAllUsers();
    bool saveMessage(const ChatMessage &msg);
    QList<ChatMessage> getMessages(const QString &user1, const QString &user2, int limit = 100);

private:
    Database() = default;
    QSqlDatabase m_db;
};

#endif
