/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *regUsernameEdit;
    QLineEdit *regPasswordEdit;
    QLineEdit *regConfirmEdit;
    QPushButton *registerButton;
    QLabel *statusLabel;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(430, 323);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("dialog-information")));
        LoginWindow->setWindowIcon(icon);
        LoginWindow->setStyleSheet(QString::fromUtf8("/* \320\221\320\260\320\267\320\276\320\262\321\213\320\265 \321\206\320\262\320\265\321\202\320\260 */\n"
"QWidget {\n"
"    background-color: #1a1a2e;\n"
"    color: #ffffff;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"}\n"
"\n"
"/* \320\232\320\275\320\276\320\277\320\272\320\270 */\n"
"QPushButton {\n"
"    background-color: #9146ff;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 10px 20px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #7a3cdb;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #5a2a8b;\n"
"}\n"
"QPushButton#logoutButton {\n"
"    background-color: #e94560;\n"
"}\n"
"QPushButton#logoutButton:hover {\n"
"    background-color: #c73a54;\n"
"}\n"
"\n"
"/* \320\237\320\276\320\273\321\217 \320\262\320\262\320\276\320\264\320\260 */\n"
"QLineEdit {\n"
"    background-color: #16213e;\n"
"    border: 1px solid #9146ff;\n"
"    border-radius: 10px;\n"
"    padding: 10px;\n"
"    color: #ffffff;\n"
"}\n"
""
                        "QLineEdit:focus {\n"
"    border: 2px solid #b388ff;\n"
"}\n"
"\n"
"/* \320\222\320\272\320\273\320\260\320\264\320\272\320\270 (\320\264\320\273\321\217 \320\276\320\272\320\275\320\260 \320\273\320\276\320\263\320\270\320\275\320\260) */\n"
"QTabWidget::pane {\n"
"    border: 1px solid #9146ff;\n"
"    border-radius: 12px;\n"
"    background-color: #0f3460;\n"
"}\n"
"QTabBar::tab {\n"
"    background-color: #16213e;\n"
"    color: #aaaaaa;\n"
"    padding: 10px 20px;\n"
"    border-top-left-radius: 8px;\n"
"    border-top-right-radius: 8px;\n"
"}\n"
"QTabBar::tab:selected {\n"
"    background-color: #9146ff;\n"
"    color: white;\n"
"}\n"
"\n"
"/* \320\241\320\277\320\270\321\201\320\272\320\270 (\320\272\320\276\320\275\321\202\320\260\320\272\321\202\321\213, \321\207\320\260\321\202) */\n"
"QListWidget {\n"
"    background-color: #16213e;\n"
"    border: 1px solid #9146ff;\n"
"    border-radius: 12px;\n"
"    padding: 5px;\n"
"}\n"
"QListWidget::item {\n"
"    padding: 8px;\n"
"    border-radius: 6px;\n"
""
                        "    color: #dddddd;\n"
"}\n"
"QListWidget::item:selected {\n"
"    background-color: #9146ff;\n"
"    color: white;\n"
"}\n"
"QListWidget::item:hover {\n"
"    background-color: #2a2a4a;\n"
"}\n"
"\n"
"/* \320\234\320\265\321\202\320\272\320\270 (\321\201\321\202\320\260\321\202\321\203\321\201, \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\270) */\n"
"QLabel {\n"
"    color: #cccccc;\n"
"}\n"
"QLabel#statusLabel {\n"
"    color: #aaaaaa;\n"
"}"));
        verticalLayout = new QVBoxLayout(LoginWindow);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(LoginWindow);
        tabWidget->setObjectName("tabWidget");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(10);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 5px;\n"
"    background-color: white;\n"
"}\n"
"QTabBar::tab {\n"
"    padding: 8px 16px;\n"
"    margin-right: 2px;\n"
"}\n"
"QTabBar::tab:selected {\n"
"    background-color: #0078d7;\n"
"    color: white;\n"
"}"));
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        usernameEdit = new QLineEdit(tab);
        usernameEdit->setObjectName("usernameEdit");
        usernameEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    margin: 5px;\n"
"}"));

        verticalLayout_2->addWidget(usernameEdit);

        passwordEdit = new QLineEdit(tab);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    margin: 5px;\n"
"}"));
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_2->addWidget(passwordEdit);

        loginButton = new QPushButton(tab);
        loginButton->setObjectName("loginButton");
        loginButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #28a745;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    margin: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #218838;\n"
"}"));

        verticalLayout_2->addWidget(loginButton);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        regUsernameEdit = new QLineEdit(tab_2);
        regUsernameEdit->setObjectName("regUsernameEdit");
        regUsernameEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    margin: 5px;\n"
"}"));

        verticalLayout_3->addWidget(regUsernameEdit);

        regPasswordEdit = new QLineEdit(tab_2);
        regPasswordEdit->setObjectName("regPasswordEdit");
        regPasswordEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    margin: 5px;\n"
"}"));
        regPasswordEdit->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_3->addWidget(regPasswordEdit);

        regConfirmEdit = new QLineEdit(tab_2);
        regConfirmEdit->setObjectName("regConfirmEdit");
        regConfirmEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    margin: 5px;\n"
"}"));
        regConfirmEdit->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_3->addWidget(regConfirmEdit);

        registerButton = new QPushButton(tab_2);
        registerButton->setObjectName("registerButton");
        registerButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #0078d7;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    margin: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #005a9e;\n"
"}"));

        verticalLayout_3->addWidget(registerButton);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        statusLabel = new QLabel(LoginWindow);
        statusLabel->setObjectName("statusLabel");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(9);
        statusLabel->setFont(font1);
        statusLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #6c757d;\n"
"    padding: 5px;\n"
"}"));
        statusLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(statusLabel);


        retranslateUi(LoginWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "\320\222\321\205\320\276\320\264 \320\262 \321\207\320\260\321\202", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        passwordEdit->setInputMask(QString());
        passwordEdit->setText(QString());
        passwordEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("LoginWindow", "\360\237\224\220 \320\222\321\205\320\276\320\264", nullptr));
        regUsernameEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        regPasswordEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        regConfirmEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\266\320\264\320\265\320\275\320\270\320\265 \320\277\320\260\321\200\320\276\320\273\321\217", nullptr));
        registerButton->setText(QCoreApplication::translate("LoginWindow", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("LoginWindow", "\360\237\223\235 \320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        statusLabel->setText(QCoreApplication::translate("LoginWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\320\275\320\275\321\213\320\265 \320\264\320\273\321\217 \320\262\321\205\320\276\320\264\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
