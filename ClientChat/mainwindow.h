#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QListWidgetItem>
#include <QMainWindow>
#include <QMap>
#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class ChatWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QString &username, QWidget *parent = nullptr);
    ~MainWindow();
    void setClient(ChatClient *client);

private slots:
    void onUserSelected(QListWidgetItem *item);
    void onLogout();
    void requestUserList();

private:
    void onMessageReceived(const ChatMessage &msg);
    void updateUserList(const QMap<QString, bool> &users);

private:
    Ui::MainWindow *ui;
    ChatClient *m_client;
    QString m_username;
    QMap<QString, ChatWidget*> m_chatWidgets;
};

#endif
