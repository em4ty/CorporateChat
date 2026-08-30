#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>
#include <QDateTime>
#include <QUuid>
#include <QJsonObject>

// Типы сообщений
enum class MsgType {
    Login = 1,          // запрос входа
    LoginOK = 2,        // вход успешен
    LoginFailed = 3,    // вход отклонен
    Register = 4,       // регистрация
    RegisterOK = 5,     // регистрация успешна
    RegisterFailed = 6, // регистрация отклонена
    TextMessage = 7,    // текстовое сообщение
    UserList = 8,       // список пользователей
    Status = 9,         // статус пользователя (онлайн/офлайн)
    Logout = 10,         // выход
    History = 11,
    File = 12,
    FileAck = 13,
    FileTransferStart = 14, // клиент сообщает серверу, что хочет передать файл
    FileTransferAck = 15, // севрвер подтверждает, что готов принять
    FileTransferEnd= 16, // конец передачи
    FileInfo = 17,      // уведомление о файле (имя + ID)
    FileRequest = 18,   // запрос на скачивание по ID
    FileResponse = 19,  // конец передачи
};

// Структура сообщения
struct ChatMessage
{

    MsgType type;           // тип сообщения
    QString from;           // отправитель
    QString to;             // получатель (пусто для всех)
    QString content;        // содержимое
    QString messageId;      // уникальный ID сообщения
    QDateTime timestamp;    // время отправки
    QString fileId;      // уникальный ID файла (генерирует сервер)
    QString fileName;    // имя файла (для отображения)
    quint64 fileSize;    // размер в байтах
    // Сериализация в JSON
    QJsonObject toJson() const {
        QJsonObject obj;
        obj["type"] = static_cast<int>(type);
        obj["from"] = from;
        obj["to"] = to;
        obj["content"] = content;
        obj["messageId"] = messageId;
        obj["timestamp"] = timestamp.toString(Qt::ISODate);
        obj["fileName"] = fileName;
        obj["fileId"] = fileId;
        obj["fileSize"] = static_cast<qint64>(fileSize);
        return obj;
    }

    // Десериализация из JSON
    static ChatMessage fromJson(const QJsonObject &obj) {
        ChatMessage msg;
        msg.type = static_cast<MsgType>(obj["type"].toInt());
        msg.from = obj["from"].toString();
        msg.to = obj["to"].toString();
        msg.content = obj["content"].toString();
        msg.messageId = obj["messageId"].toString();
        msg.timestamp = QDateTime::fromString(obj["timestamp"].toString(), Qt::ISODate);
        msg.fileName = obj["fileName"].toString();
        msg.fileSize = static_cast<quint64>(obj["fileSize"].toInteger());
        msg.fileId = obj["fileId"].toString();
        return msg;
    }
};

#endif // MESSAGE_H
