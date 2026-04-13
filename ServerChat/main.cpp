#include <QCoreApplication>
#include <QDebug>
#include "server.h"
#include "database.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QString dbPath = "C:/Users/yumk9/Documents/ServerChat/chat.db";

    qDebug() << "[SERVER] DB path:" << dbPath;
    // Инициализация базы данных
    if(!Database::instance().init(dbPath)) {
        qDebug() << "❌ Failed to initialize database";
        return 1;
    }

    // Создание и запуск сервера
    ChatServer server;

    QObject::connect(&server, &ChatServer::logMessage, [](const QString &msg) {
        qDebug().noquote() << msg;
    });

    if(!server.start(12345)) {
        return 1;
    }

    qDebug() << "📡 Chat server running on port 12345";
    qDebug() << "   Press Ctrl+C to stop\n";

    return app.exec();
}
