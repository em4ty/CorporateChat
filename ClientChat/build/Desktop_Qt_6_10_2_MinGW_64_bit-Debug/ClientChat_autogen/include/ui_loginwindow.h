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
        LoginWindow->resize(400, 300);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("dialog-information")));
        LoginWindow->setWindowIcon(icon);
        LoginWindow->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #f0f0f0;\n"
"}"));
        verticalLayout = new QVBoxLayout(LoginWindow);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(LoginWindow);
        tabWidget->setObjectName("tabWidget");
        QFont font;
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
        passwordEdit->setEchoMode(QLineEdit::Password);
        passwordEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    margin: 5px;\n"
"}"));

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
        regPasswordEdit->setEchoMode(QLineEdit::Password);
        regPasswordEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    margin: 5px;\n"
"}"));

        verticalLayout_3->addWidget(regPasswordEdit);

        regConfirmEdit = new QLineEdit(tab_2);
        regConfirmEdit->setObjectName("regConfirmEdit");
        regConfirmEdit->setEchoMode(QLineEdit::Password);
        regConfirmEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    margin: 5px;\n"
"}"));

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
        font1.setPointSize(9);
        statusLabel->setFont(font1);
        statusLabel->setAlignment(Qt::AlignCenter);
        statusLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #6c757d;\n"
"    padding: 5px;\n"
"}"));

        verticalLayout->addWidget(statusLabel);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "\320\222\321\205\320\276\320\264 \320\262 \321\207\320\260\321\202", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\360\237\221\244 \320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\360\237\224\222 \320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginWindow", "\360\237\232\200 \320\222\320\276\320\271\321\202\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("LoginWindow", "\360\237\224\220 \320\222\321\205\320\276\320\264", nullptr));
        regUsernameEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\360\237\221\244 \320\230\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        regPasswordEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\360\237\224\222 \320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        regConfirmEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "\360\237\224\222 \320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\266\320\264\320\265\320\275\320\270\320\265 \320\277\320\260\321\200\320\276\320\273\321\217", nullptr));
        registerButton->setText(QCoreApplication::translate("LoginWindow", "\360\237\223\235 \320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("LoginWindow", "\360\237\223\235 \320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        statusLabel->setText(QCoreApplication::translate("LoginWindow", "\360\237\222\241 \320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\320\275\320\275\321\213\320\265 \320\264\320\273\321\217 \320\262\321\205\320\276\320\264\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
