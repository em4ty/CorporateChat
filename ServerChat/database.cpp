#include "database.h"
#include <QDebug>
#include <QUuid>

Database& Database::instance()
{
    static Database db;
    return db;
}

bool Database::init(const QString &path)
{
    qDebug() << "[DB] Initializing database at:" << path;

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if(!m_db.open()) {
        qDebug() << "[DB] Failed to open database:" << m_db.lastError().text();
        return false;
    }
    qDebug() << "[DB] Database opened successfully";

    QSqlQuery query;

    // Таблица пользователей
    if(!query.exec("CREATE TABLE IF NOT EXISTS users ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "username TEXT UNIQUE NOT NULL,"
                    "password_hash TEXT NOT NULL,"
                    "created_at DATETIME DEFAULT CURRENT_TIMESTAMP)")) {
        qDebug() << "[DB] Failed to create users table:" << query.lastError().text();
        return false;
    }
    qDebug() << "[DB] Users table ready";

    // Таблица сообщений
    if(!query.exec("CREATE TABLE IF NOT EXISTS messages ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "message_id TEXT UNIQUE NOT NULL,"
                    "sender TEXT NOT NULL,"
                    "receiver TEXT NOT NULL,"
                    "content TEXT,"
                    "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,"
                    "is_read INTEGER DEFAULT 0)")) {
        qDebug() << "[DB] Failed to create messages table:" << query.lastError().text();
        return false;
    }
    qDebug() << "[DB] Messages table ready";

    return true;
}

bool Database::addUser(const QString &username, const QString &passwordHash)
{
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password_hash) VALUES (?, ?)");
    query.addBindValue(username);
    query.addBindValue(passwordHash);

    return query.exec();
}

bool Database::checkUser(const QString &username, const QString &passwordHash)
{
    QSqlQuery query;
    query.prepare("SELECT id FROM users WHERE username = ? AND password_hash = ?");
    query.addBindValue(username);
    query.addBindValue(passwordHash);
    query.exec();

    return query.next();
}

QStringList Database::getAllUsers()
{
    QStringList users;
    QSqlQuery query("SELECT username FROM users");

    while(query.next()) {
        users << query.value(0).toString();
    }
    return users;
}

bool Database::saveMessage(const ChatMessage &msg)
{
    QSqlQuery query;
    query.prepare("INSERT INTO messages (message_id, sender, receiver, content, timestamp) "
                  "VALUES (?, ?, ?, ?, ?)");
    query.addBindValue(msg.messageId.isEmpty() ? QUuid::createUuid().toString() : msg.messageId);
    query.addBindValue(msg.from);
    query.addBindValue(msg.to.isEmpty() ? "all" : msg.to);
    query.addBindValue(msg.content);
    query.addBindValue(msg.timestamp);

    return query.exec();
}

QList<ChatMessage> Database::getMessages(const QString &user1, const QString &user2, int limit)
{
    QList<ChatMessage> messages;
    QSqlQuery query;
    query.prepare("SELECT sender, receiver, content, timestamp FROM messages "
                  "WHERE (sender = ? AND receiver = ?) OR (sender = ? AND receiver = ?) "
                  "ORDER BY timestamp ASC LIMIT ?");
    query.addBindValue(user1);
    query.addBindValue(user2);
    query.addBindValue(user2);
    query.addBindValue(user1);
    query.addBindValue(limit);
    query.exec();

    while(query.next()) {
        ChatMessage msg;
        msg.from = query.value(0).toString();
        msg.to = query.value(1).toString();
        msg.content = query.value(2).toString();
        msg.timestamp = query.value(3).toDateTime();
        msg.type = MsgType::TextMessage;
        messages.append(msg);
    }

    return messages;
}
