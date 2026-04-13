#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    ChatClient* getClient() const { return m_client; }

private slots:
    void onLoginClicked();
    void onRegisterClicked();
    void onConnected();
    void onLoginSuccess();
    void onError(const QString &error);

signals:
    void loginSuccessful(const QString &username);

private:
    Ui::LoginWindow *ui;
    ChatClient *m_client;

};

#endif // LOGINWINDOW_H
