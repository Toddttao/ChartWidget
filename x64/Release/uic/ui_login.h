/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginClass
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *login;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *p_register;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_12;
    QComboBox *servermode;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *password;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *username;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QDialog *loginClass)
    {
        if (loginClass->objectName().isEmpty())
            loginClass->setObjectName("loginClass");
        loginClass->resize(645, 433);
        layoutWidget = new QWidget(loginClass);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 15, 581, 411));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        login = new QPushButton(layoutWidget);
        login->setObjectName("login");
        login->setMinimumSize(QSize(150, 50));

        horizontalLayout_4->addWidget(login);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        p_register = new QPushButton(layoutWidget);
        p_register->setObjectName("p_register");
        p_register->setMinimumSize(QSize(150, 50));

        horizontalLayout_4->addWidget(p_register);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_4, 7, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 6, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        QFont font;
        font.setPointSize(16);
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_12);

        servermode = new QComboBox(layoutWidget);
        servermode->addItem(QString());
        servermode->addItem(QString());
        servermode->setObjectName("servermode");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(servermode->sizePolicy().hasHeightForWidth());
        servermode->setSizePolicy(sizePolicy);
        servermode->setMinimumSize(QSize(300, 50));

        horizontalLayout_3->addWidget(servermode, 0, Qt::AlignmentFlag::AlignLeft);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_3, 5, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_7 = new QSpacerItem(80, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        password = new QLineEdit(layoutWidget);
        password->setObjectName("password");
        sizePolicy.setHeightForWidth(password->sizePolicy().hasHeightForWidth());
        password->setSizePolicy(sizePolicy);
        password->setMinimumSize(QSize(300, 50));

        horizontalLayout_2->addWidget(password, 0, Qt::AlignmentFlag::AlignRight);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_11);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setFont(font);

        horizontalLayout->addWidget(label, 0, Qt::AlignmentFlag::AlignLeft);

        horizontalSpacer_9 = new QSpacerItem(60, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        username = new QLineEdit(layoutWidget);
        username->setObjectName("username");
        sizePolicy.setHeightForWidth(username->sizePolicy().hasHeightForWidth());
        username->setSizePolicy(sizePolicy);
        username->setMinimumSize(QSize(300, 50));

        horizontalLayout->addWidget(username, 0, Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 8, 0, 1, 1);


        retranslateUi(loginClass);

        QMetaObject::connectSlotsByName(loginClass);
    } // setupUi

    void retranslateUi(QDialog *loginClass)
    {
        loginClass->setWindowTitle(QCoreApplication::translate("loginClass", "login", nullptr));
        login->setText(QCoreApplication::translate("loginClass", "\347\231\273\345\275\225", nullptr));
        p_register->setText(QCoreApplication::translate("loginClass", "\346\263\250\345\206\214", nullptr));
        label_3->setText(QCoreApplication::translate("loginClass", "\346\234\215\345\212\241\346\250\241\345\274\217", nullptr));
        servermode->setItemText(0, QCoreApplication::translate("loginClass", "TCP", nullptr));
        servermode->setItemText(1, QCoreApplication::translate("loginClass", "UDP", nullptr));

        label_2->setText(QCoreApplication::translate("loginClass", "\345\257\206\347\240\201", nullptr));
        label->setText(QCoreApplication::translate("loginClass", "\347\224\250\346\210\267\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginClass: public Ui_loginClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
