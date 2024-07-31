/********************************************************************************
** Form generated from reading UI file 'mainWindows.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWS_H
#define UI_MAINWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QTextEdit *sendtext;
    QTextEdit *recvtext;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QPushButton *send;
    QPushButton *back;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(625, 508);
        layoutWidget = new QWidget(Form);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 20, 511, 471));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(10);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        sendtext = new QTextEdit(layoutWidget);
        sendtext->setObjectName("sendtext");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sendtext->sizePolicy().hasHeightForWidth());
        sendtext->setSizePolicy(sizePolicy);
        sendtext->setMinimumSize(QSize(0, 100));

        gridLayout->addWidget(sendtext, 2, 0, 1, 1);

        recvtext = new QTextEdit(layoutWidget);
        recvtext->setObjectName("recvtext");

        gridLayout->addWidget(recvtext, 1, 0, 1, 1);

        layoutWidget1 = new QWidget(Form);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(530, 340, 82, 81));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        send = new QPushButton(layoutWidget1);
        send->setObjectName("send");

        verticalLayout->addWidget(send);

        back = new QPushButton(layoutWidget1);
        back->setObjectName("back");

        verticalLayout->addWidget(back);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        send->setText(QCoreApplication::translate("Form", "\345\217\221\351\200\201", nullptr));
        back->setText(QCoreApplication::translate("Form", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWS_H
