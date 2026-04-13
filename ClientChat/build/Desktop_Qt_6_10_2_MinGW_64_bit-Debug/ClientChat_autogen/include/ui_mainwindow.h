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
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *leftPanel;
    QLabel *label;
    QListWidget *userList;
    QPushButton *logoutButton;
    QStackedWidget *chatStack;
    QWidget *emptyPage;
    QVBoxLayout *verticalLayout;
    QLabel *emptyLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        leftPanel = new QVBoxLayout();
        leftPanel->setObjectName("leftPanel");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        leftPanel->addWidget(label);

        userList = new QListWidget(centralwidget);
        userList->setObjectName("userList");
        userList->setStyleSheet(QString::fromUtf8("QListWidget::item {\n"
"    padding: 8px;\n"
"}\n"
"QListWidget::item:selected {\n"
"    background-color: #0078d7;\n"
"    color: white;\n"
"}"));

        leftPanel->addWidget(userList);

        logoutButton = new QPushButton(centralwidget);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #dc3545;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #c82333;\n"
"}"));

        leftPanel->addWidget(logoutButton);


        horizontalLayout->addLayout(leftPanel);

        chatStack = new QStackedWidget(centralwidget);
        chatStack->setObjectName("chatStack");
        emptyPage = new QWidget();
        emptyPage->setObjectName("emptyPage");
        verticalLayout = new QVBoxLayout(emptyPage);
        verticalLayout->setObjectName("verticalLayout");
        emptyLabel = new QLabel(emptyPage);
        emptyLabel->setObjectName("emptyLabel");
        emptyLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(emptyLabel);

        chatStack->addWidget(emptyPage);

        horizontalLayout->addWidget(chatStack);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        chatStack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\247\320\260\321\202 - \320\234\320\265\321\201\321\201\320\265\320\275\320\264\320\266\320\265\321\200", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\360\237\221\245 \320\232\320\276\320\275\321\202\320\260\320\272\321\202\321\213", nullptr));
        logoutButton->setText(QCoreApplication::translate("MainWindow", "\360\237\232\252 \320\222\321\213\320\271\321\202\320\270", nullptr));
        emptyLabel->setText(QCoreApplication::translate("MainWindow", "\360\237\222\254 \320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\201\320\276\320\261\320\265\321\201\320\265\320\264\320\275\320\270\320\272\320\260 \320\270\320\267 \321\201\320\277\320\270\321\201\320\272\320\260 \321\201\320\273\320\265\320\262\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
