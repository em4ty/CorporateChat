/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_main;
    QWidget *titleBar;
    QHBoxLayout *horizontalLayout_titleBar;
    QLabel *titleLabel;
    QSpacerItem *titleSpacer;
    QPushButton *minimizeButton;
    QPushButton *maximizeButton;
    QPushButton *closeButton;
    QWidget *mainContent;
    QHBoxLayout *horizontalLayout_main;
    QWidget *leftPanel;
    QVBoxLayout *verticalLayout_left;
    QListWidget *userList;
    QWidget *profileWidget;
    QHBoxLayout *horizontalLayout_profile;
    QLabel *userAvatarLabel;
    QLabel *usernameLabel;
    QSpacerItem *profileSpacer;
    QPushButton *logoutButton;
    QStackedWidget *chatStack;
    QWidget *emptyPage;
    QVBoxLayout *verticalLayout_empty;
    QLabel *emptyLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 650);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_main = new QVBoxLayout(centralwidget);
        verticalLayout_main->setSpacing(0);
        verticalLayout_main->setObjectName("verticalLayout_main");
        verticalLayout_main->setContentsMargins(0, 0, 0, 0);
        titleBar = new QWidget(centralwidget);
        titleBar->setObjectName("titleBar");
        titleBar->setMinimumSize(QSize(0, 40));
        titleBar->setMaximumSize(QSize(16777215, 40));
        titleBar->setStyleSheet(QString::fromUtf8("QWidget#titleBar {\n"
"    background-color: #1e1e2f;\n"
"    border-bottom: 1px solid #2a2a3e;\n"
"}"));
        horizontalLayout_titleBar = new QHBoxLayout(titleBar);
        horizontalLayout_titleBar->setSpacing(0);
        horizontalLayout_titleBar->setObjectName("horizontalLayout_titleBar");
        horizontalLayout_titleBar->setContentsMargins(12, 0, 8, 0);
        titleLabel = new QLabel(titleBar);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #e0e0e0;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}"));

        horizontalLayout_titleBar->addWidget(titleLabel);

        titleSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_titleBar->addItem(titleSpacer);

        minimizeButton = new QPushButton(titleBar);
        minimizeButton->setObjectName("minimizeButton");
        minimizeButton->setMinimumSize(QSize(30, 30));
        minimizeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    color: #e0e0e0;\n"
"    border: none;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2a2a4a;\n"
"}"));

        horizontalLayout_titleBar->addWidget(minimizeButton);

        maximizeButton = new QPushButton(titleBar);
        maximizeButton->setObjectName("maximizeButton");
        maximizeButton->setMinimumSize(QSize(30, 30));
        maximizeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    color: #e0e0e0;\n"
"    border: none;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2a2a4a;\n"
"}"));

        horizontalLayout_titleBar->addWidget(maximizeButton);

        closeButton = new QPushButton(titleBar);
        closeButton->setObjectName("closeButton");
        closeButton->setMinimumSize(QSize(30, 30));
        closeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    color: #e0e0e0;\n"
"    border: none;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #e81123;\n"
"    color: white;\n"
"}"));

        horizontalLayout_titleBar->addWidget(closeButton);


        verticalLayout_main->addWidget(titleBar);

        mainContent = new QWidget(centralwidget);
        mainContent->setObjectName("mainContent");
        mainContent->setStyleSheet(QString::fromUtf8("QWidget#mainContent {\n"
"    background-color: #1a1a2e;\n"
"}"));
        horizontalLayout_main = new QHBoxLayout(mainContent);
        horizontalLayout_main->setSpacing(0);
        horizontalLayout_main->setObjectName("horizontalLayout_main");
        horizontalLayout_main->setContentsMargins(0, 0, 0, 0);
        leftPanel = new QWidget(mainContent);
        leftPanel->setObjectName("leftPanel");
        leftPanel->setMinimumSize(QSize(220, 0));
        leftPanel->setMaximumSize(QSize(300, 16777215));
        leftPanel->setStyleSheet(QString::fromUtf8("QWidget#leftPanel {\n"
"    background-color: #1e1e2f;\n"
"}"));
        verticalLayout_left = new QVBoxLayout(leftPanel);
        verticalLayout_left->setSpacing(0);
        verticalLayout_left->setObjectName("verticalLayout_left");
        verticalLayout_left->setContentsMargins(0, 0, 0, 0);
        userList = new QListWidget(leftPanel);
        userList->setObjectName("userList");
        userList->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    background-color: #1e1e2f;\n"
"    border: none;\n"
"    outline: none;\n"
"}\n"
"QListWidget::item {\n"
"    padding: 12px 8px;\n"
"    border-bottom: 1px solid #2a2a3e;\n"
"    color: #e0e0e0;\n"
"}\n"
"QListWidget::item:selected {\n"
"    background-color: #2a2a4a;\n"
"    border-left: 3px solid #9146ff;\n"
"}\n"
"QListWidget::item:hover {\n"
"    background-color: #2a2a3e;\n"
"}"));

        verticalLayout_left->addWidget(userList);

        profileWidget = new QWidget(leftPanel);
        profileWidget->setObjectName("profileWidget");
        profileWidget->setMinimumSize(QSize(0, 70));
        profileWidget->setMaximumSize(QSize(16777215, 70));
        profileWidget->setStyleSheet(QString::fromUtf8("QWidget#profileWidget {\n"
"    background-color: #1a1a2e;\n"
"    border-top: 1px solid #2a2a3e;\n"
"}"));
        horizontalLayout_profile = new QHBoxLayout(profileWidget);
        horizontalLayout_profile->setSpacing(10);
        horizontalLayout_profile->setObjectName("horizontalLayout_profile");
        horizontalLayout_profile->setContentsMargins(10, 5, 10, 5);
        userAvatarLabel = new QLabel(profileWidget);
        userAvatarLabel->setObjectName("userAvatarLabel");
        userAvatarLabel->setMinimumSize(QSize(40, 40));
        userAvatarLabel->setMaximumSize(QSize(40, 40));
        userAvatarLabel->setStyleSheet(QString::fromUtf8("border-radius: 20px; background: transparent;"));

        horizontalLayout_profile->addWidget(userAvatarLabel);

        usernameLabel = new QLabel(profileWidget);
        usernameLabel->setObjectName("usernameLabel");
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        usernameLabel->setFont(font);
        usernameLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #e0e0e0;\n"
"}"));

        horizontalLayout_profile->addWidget(usernameLabel);

        profileSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_profile->addItem(profileSpacer);

        logoutButton = new QPushButton(profileWidget);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setMinimumSize(QSize(40, 40));
        logoutButton->setMaximumSize(QSize(40, 40));
        logoutButton->setStyleSheet(QString::fromUtf8("QPushButton#logoutButton {\n"
"    background-color: transparent;\n"
"    color: #e0e0e0;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton#logoutButton:hover {\n"
"    background-color: #3a3a4e;\n"
"    color: #ffffff;\n"
"}"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::WindowClose));
        logoutButton->setIcon(icon);

        horizontalLayout_profile->addWidget(logoutButton);


        verticalLayout_left->addWidget(profileWidget);


        horizontalLayout_main->addWidget(leftPanel);

        chatStack = new QStackedWidget(mainContent);
        chatStack->setObjectName("chatStack");
        emptyPage = new QWidget();
        emptyPage->setObjectName("emptyPage");
        verticalLayout_empty = new QVBoxLayout(emptyPage);
        verticalLayout_empty->setSpacing(0);
        verticalLayout_empty->setObjectName("verticalLayout_empty");
        emptyLabel = new QLabel(emptyPage);
        emptyLabel->setObjectName("emptyLabel");
        emptyLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_empty->addWidget(emptyLabel);

        chatStack->addWidget(emptyPage);

        horizontalLayout_main->addWidget(chatStack);


        verticalLayout_main->addWidget(mainContent);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        chatStack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\247\320\260\321\202", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "\360\237\222\254 \320\247\320\260\321\202", nullptr));
        minimizeButton->setText(QCoreApplication::translate("MainWindow", "\342\200\224", nullptr));
        maximizeButton->setText(QCoreApplication::translate("MainWindow", "\342\226\241", nullptr));
        closeButton->setText(QCoreApplication::translate("MainWindow", "\342\234\225", nullptr));
        userAvatarLabel->setText(QString());
        usernameLabel->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        logoutButton->setText(QString());
        emptyLabel->setText(QCoreApplication::translate("MainWindow", "\360\237\222\254 \320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\264\320\270\320\260\320\273\320\276\320\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
