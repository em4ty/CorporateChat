#include <QApplication>
#include "loginwindow.h"
#include "mainwindow.h"
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFile styleFile(":/style.qss");   // путь зависит от префикса в .qrc
    if (styleFile.open(QFile::ReadOnly | QFile::Text)) {
        QString style = styleFile.readAll();
        app.setStyleSheet(style);
        styleFile.close();
        qDebug() << "Стиль успешно загружен!";
    } else {
        qDebug() << "Не удалось загрузить стиль. Проверь путь в resources.qrc";
    }

    QFont defaultFont("Segoe UI", 12);
    app.setFont(defaultFont);

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
