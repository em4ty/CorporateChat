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

private slots:
    void onSendClicked();
    void onMessageReceived(const ChatMessage &msg);
    void onHistoryReceived(const QList<ChatMessage> &history);  // 🔴 НОВЫЙ СЛОТ

private:
    void addMyMessage(const QString &content);
    void addOtherMessage(const QString &from, const QString &content);

private:
    Ui::ChatWidget *ui;
    ChatClient *m_client;
    QString m_myUsername;
    QString m_peerUsername;
};

#endif
