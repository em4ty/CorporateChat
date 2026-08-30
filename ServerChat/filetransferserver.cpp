#include "filetransferserver.h"
#include <QTcpSocket>
#include <QDebug>
#include <QDir>
#include <QUuid>


FileTransferServer::FileTransferServer(QObject *parent)
    :QTcpServer(parent){

}
bool FileTransferServer::start(quint16 port){
    if(listen(QHostAddress::Any, port)){
        emit logMessage("Server start on port" + QString::number(port));
        return true;
    }
    emit logMessage("Crashed server on port" + QString::number(port));
    return false;
}

void FileTransferServer::incomingConnection(qintptr socketDescriptor) {
    QTcpSocket *socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &FileTransferServer::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &FileTransferServer::onDisconnected);
}

void FileTransferServer::onReadyRead()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    if (!socket) return;

    m_buffers[socket].append(socket->readAll());

    QDataStream stream(&m_buffers[socket], QIODevice::ReadOnly);
    if (m_buffers[socket].size() < 4) return;

    QString filename;
    quint64 fileSize;
    QByteArray fileData;

    // Читаем имя и размер
    stream >> filename >> fileSize;

    // Проверяем, что данных достаточно
    int headerSize = 4 + filename.length() * 2 + 8; // приблизительно
    if (m_buffers[socket].size() < headerSize + fileSize) {
        return; // ждём ещё данные
    }

    // Читаем данные файла
    stream >> fileData;

    // Сохраняем файл
    QString fileId = saveFile(filename, fileData);

    if (!fileId.isEmpty()) {
        emit logMessage("File saved with ID: " + fileId);
        emit fileSaved(fileId, filename, fileSize);
    }

    m_buffers[socket].clear();
}

QString FileTransferServer::saveFile(const QString &filename, const QByteArray &data){
    if(filename.isEmpty() || data.isEmpty()){
        emit logMessage("Error: empty filename or data");
        return QString();
    }
    QDir dir;
    if(!dir.exists("uploads")){
        if(!dir.mkdir("uploads")){
            emit logMessage("Error: cannot ctreate uploads folder");
            return QString();
        }
    }

    QString fileId = QUuid::createUuid().toString(QUuid::WithoutBraces);
    QString filePath = "uploads/" + fileId + "_" + filename;
    QFile file(filePath);
    if(!file.open(QIODevice::WriteOnly)){
        emit logMessage("Error: cannot open file for writting " + filePath);
        return QString();
    }

    quint64 byteWritten = file.write(data);
    file.close();

    if (byteWritten != data.size()){
        emit logMessage("Error: incomplete file write");
        return QString();
    }
    emit logMessage("File saved: " + filename + "("+ QString::number(data.size())+"bytes");
    return fileId;


}
void FileTransferServer::onDisconnected(){
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    if(!socket)return;
    m_buffers.remove(socket);
    m_filenames.remove(socket);

    socket->deleteLater();



    emit logMessage("File client disconnected");

}
