#ifndef FILETRANSFERSERVER_H
#define FILETRANSFERSERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>

class FileTransferServer : public QTcpServer{
    Q_OBJECT
public:
    explicit FileTransferServer(QObject *parent = nullptr);
    bool start(quint16 port);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

signals:
    void logMessage(const QString &msg);
    void fileSaved(const QString &fileId, const QString &filename, quint64 fileSize);
private:
    void onReadyRead();
    void onDisconnected();
    QString saveFile(const QString &filename, const QByteArray &data);
    QMap<QTcpSocket*, QByteArray> m_buffers; //буфер для каждого клиента
    QMap<QTcpSocket*, QString> m_filenames; // имя файла для каждого клиента
};


#endif // FILETRANSFERSERVER_H
