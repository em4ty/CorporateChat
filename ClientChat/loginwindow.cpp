#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    m_client = new ChatClient(this);

    connect(m_client, &ChatClient::connected, this, &LoginWindow::onConnected);
    connect(m_client, &ChatClient::messageReceived, this, [this](const ChatMessage &msg) {
        if(msg.type == MsgType::LoginOK) {
            onLoginSuccess();
        } else if(msg.type == MsgType::LoginFailed) {
            onError(msg.content);
        } else if(msg.type == MsgType::RegisterOK) {
            QMessageBox::information(this, "Регистрация", "Пользователь создан! Теперь войдите.");
            ui->tabWidget->setCurrentIndex(0); // переключаемся на вкладку входа
        } else if(msg.type == MsgType::RegisterFailed) {
            onError(msg.content);
        }
    });

    connect(ui->loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginClicked);
    connect(ui->registerButton, &QPushButton::clicked, this, &LoginWindow::onRegisterClicked);

    m_client->connectToServer("127.0.0.1", 12345);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::onLoginClicked()
{
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();

    if(username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите имя пользователя и пароль");
        return;
    }

    ui->statusLabel->setText("Подключение...");
    m_client->login(username, password);
}

void LoginWindow::onRegisterClicked()
{
    QString username = ui->regUsernameEdit->text();
    QString password = ui->regPasswordEdit->text();
    QString confirm = ui->regConfirmEdit->text();

    if(username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Заполните все поля");
        return;
    }

    if(password != confirm) {
        QMessageBox::warning(this, "Ошибка", "Пароли не совпадают");
        return;
    }

    m_client->registerUser(username, password);
}

void LoginWindow::onConnected()
{
    ui->statusLabel->setText("Подключено к серверу");
}

void LoginWindow::onLoginSuccess()
{
    // Устанавливаем флаг авторизации перед передачей клиента
    m_client->setAuthenticated(true);

    emit loginSuccessful(ui->usernameEdit->text());
    hide();
}
void LoginWindow::onError(const QString &error)
{
    ui->statusLabel->setText(error);
    QMessageBox::warning(this, "Ошибка", error);
}
