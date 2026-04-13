/********************************************************************************
** Form generated from reading UI file 'chatwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGET_H
#define UI_CHATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWidget
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *chatDisplay;
    QHBoxLayout *horizontalLayout;
    QLineEdit *messageEdit;
    QPushButton *sendButton;

    void setupUi(QWidget *ChatWidget)
    {
        if (ChatWidget->objectName().isEmpty())
            ChatWidget->setObjectName("ChatWidget");
        ChatWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(ChatWidget);
        verticalLayout->setObjectName("verticalLayout");
        chatDisplay = new QListWidget(ChatWidget);
        chatDisplay->setObjectName("chatDisplay");
        chatDisplay->setSpacing(5);

        verticalLayout->addWidget(chatDisplay);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        messageEdit = new QLineEdit(ChatWidget);
        messageEdit->setObjectName("messageEdit");

        horizontalLayout->addWidget(messageEdit);

        sendButton = new QPushButton(ChatWidget);
        sendButton->setObjectName("sendButton");

        horizontalLayout->addWidget(sendButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ChatWidget);

        QMetaObject::connectSlotsByName(ChatWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatWidget)
    {
        messageEdit->setPlaceholderText(QCoreApplication::translate("ChatWidget", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265...", nullptr));
        sendButton->setText(QCoreApplication::translate("ChatWidget", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        (void)ChatWidget;
    } // retranslateUi

};

namespace Ui {
    class ChatWidget: public Ui_ChatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGET_H
