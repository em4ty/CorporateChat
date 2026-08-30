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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *headerWidget;
    QHBoxLayout *horizontalLayout_header;
    QLabel *avatarLabel;
    QLabel *chatPartnerLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *statusIndicator;
    QScrollArea *chatScrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *chatLayout;
    QWidget *inputWidget;
    QHBoxLayout *horizontalLayout_input;
    QPushButton *attachButton;
    QLineEdit *messageEdit;
    QPushButton *sendButton;

    void setupUi(QWidget *ChatWidget)
    {
        if (ChatWidget->objectName().isEmpty())
            ChatWidget->setObjectName("ChatWidget");
        ChatWidget->resize(600, 650);
        verticalLayout = new QVBoxLayout(ChatWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        headerWidget = new QWidget(ChatWidget);
        headerWidget->setObjectName("headerWidget");
        headerWidget->setMinimumSize(QSize(0, 50));
        headerWidget->setStyleSheet(QString::fromUtf8("QWidget#headerWidget {\n"
"    background-color: #1e1e2f;\n"
"    border-bottom: 1px solid #2a2a3e;\n"
"}"));
        horizontalLayout_header = new QHBoxLayout(headerWidget);
        horizontalLayout_header->setSpacing(0);
        horizontalLayout_header->setObjectName("horizontalLayout_header");
        horizontalLayout_header->setContentsMargins(0, 0, 0, 0);
        avatarLabel = new QLabel(headerWidget);
        avatarLabel->setObjectName("avatarLabel");
        avatarLabel->setMinimumSize(QSize(40, 40));
        avatarLabel->setMaximumSize(QSize(40, 40));
        avatarLabel->setStyleSheet(QString::fromUtf8("border-radius: 20px; background: transparent;"));

        horizontalLayout_header->addWidget(avatarLabel);

        chatPartnerLabel = new QLabel(headerWidget);
        chatPartnerLabel->setObjectName("chatPartnerLabel");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        chatPartnerLabel->setFont(font);
        chatPartnerLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #e0e0e0;\n"
"    padding-left: 16px;\n"
"}"));

        horizontalLayout_header->addWidget(chatPartnerLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_header->addItem(horizontalSpacer);

        statusIndicator = new QLabel(headerWidget);
        statusIndicator->setObjectName("statusIndicator");
        statusIndicator->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #4caf50;\n"
"    padding-right: 16px;\n"
"}"));

        horizontalLayout_header->addWidget(statusIndicator);


        verticalLayout->addWidget(headerWidget);

        chatScrollArea = new QScrollArea(ChatWidget);
        chatScrollArea->setObjectName("chatScrollArea");
        chatScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        chatScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        chatScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 598, 538));
        chatLayout = new QVBoxLayout(scrollAreaWidgetContents);
        chatLayout->setSpacing(6);
        chatLayout->setObjectName("chatLayout");
        chatLayout->setContentsMargins(8, 8, 8, 8);
        chatScrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(chatScrollArea);

        inputWidget = new QWidget(ChatWidget);
        inputWidget->setObjectName("inputWidget");
        inputWidget->setMinimumSize(QSize(0, 60));
        inputWidget->setStyleSheet(QString::fromUtf8("QWidget#inputWidget {\n"
"    background-color: #1e1e2f;\n"
"    border-top: 1px solid #2a2a3e;\n"
"}"));
        horizontalLayout_input = new QHBoxLayout(inputWidget);
        horizontalLayout_input->setSpacing(8);
        horizontalLayout_input->setObjectName("horizontalLayout_input");
        horizontalLayout_input->setContentsMargins(12, 8, 12, 8);
        attachButton = new QPushButton(inputWidget);
        attachButton->setObjectName("attachButton");
        attachButton->setMinimumSize(QSize(40, 40));
        attachButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    color: #e0e0e0;\n"
"    border: none;\n"
"    font-size: 22px;\n"
"}\n"
"QPushButton:hover {\n"
"    color: #9146ff;\n"
"}"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::MailAttachment));
        attachButton->setIcon(icon);

        horizontalLayout_input->addWidget(attachButton);

        messageEdit = new QLineEdit(inputWidget);
        messageEdit->setObjectName("messageEdit");
        messageEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2a2a3e;\n"
"    border: 1px solid #3a3a4e;\n"
"    border-radius: 18px;\n"
"    padding: 8px 16px;\n"
"    color: #e0e0e0;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 1px solid #9146ff;\n"
"}"));

        horizontalLayout_input->addWidget(messageEdit);

        sendButton = new QPushButton(inputWidget);
        sendButton->setObjectName("sendButton");
        sendButton->setMinimumSize(QSize(40, 40));
        sendButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #9146ff;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 20px;\n"
"    font-weight: bold;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #7a3cdb;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #5a2a8b;\n"
"}"));

        horizontalLayout_input->addWidget(sendButton);


        verticalLayout->addWidget(inputWidget);


        retranslateUi(ChatWidget);

        QMetaObject::connectSlotsByName(ChatWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatWidget)
    {
        avatarLabel->setText(QString());
        chatPartnerLabel->setText(QCoreApplication::translate("ChatWidget", "\320\237\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\214", nullptr));
        statusIndicator->setText(QCoreApplication::translate("ChatWidget", "\342\227\217", nullptr));
        attachButton->setText(QString());
        messageEdit->setPlaceholderText(QCoreApplication::translate("ChatWidget", "\320\241\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265...", nullptr));
        sendButton->setText(QCoreApplication::translate("ChatWidget", "\342\236\244", nullptr));
        (void)ChatWidget;
    } // retranslateUi

};

namespace Ui {
    class ChatWidget: public Ui_ChatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGET_H
