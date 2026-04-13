#include <QApplication>
#include "loginwindow.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    LoginWindow login;
    QObject::connect(&login, &LoginWindow::loginSuccessful,
                     [&login](const QString &username) {
                         MainWindow *mainWin = new MainWindow(username);
                         mainWin->setClient(login.getClient());  // ← передаём клиента
                         mainWin->show();
                     });

    login.show();
    return app.exec();
}
