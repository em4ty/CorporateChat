#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>
#include <QScrollBar>
#include "client.h"

namespace Ui {
class ChatWidget;
}

class ChatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWidget(const QString &myUsername,
                        const QString &peerUsername,
                        ChatClient *client,
                        QWidget *parent = nullptr);
    ~ChatWidget();

public:
    void updateStatus(bool isOnline);
private slots:
    void onSendClicked();
    void onMessageReceived(const ChatMessage &msg);
    void onHistoryReceived(const ChatMessage &msg);
    void onAttachClicked();
private:
    void sendFileToServer(const QString &filePath);
    void addFileMessage(const QString &filename, const QString &fileId);
    void downloadFile(const QString &fileId);

    void addMessage(const QString &content, bool isMine, const QString &time = QString());
    void addOtherMessage(const QString &from, const QString &content);
    void updateAvatar();
private:
    Ui::ChatWidget *ui;
    ChatClient *m_client;
    QString m_myUsername;
    QString m_peerUsername;
};

#endif
