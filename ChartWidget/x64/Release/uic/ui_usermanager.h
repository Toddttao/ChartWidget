/********************************************************************************
** Form generated from reading UI file 'usermanager.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMANAGER_H
#define UI_USERMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_usermanagerClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *showlist;
    QPushButton *adduser;
    QPushButton *deletuser;
    QPushButton *changeuser;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *usermanagerClass)
    {
        if (usermanagerClass->objectName().isEmpty())
            usermanagerClass->setObjectName("usermanagerClass");
        usermanagerClass->resize(748, 531);
        centralWidget = new QWidget(usermanagerClass);
        centralWidget->setObjectName("centralWidget");
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 741, 471));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(layoutWidget);
        tableView->setObjectName("tableView");

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        showlist = new QPushButton(layoutWidget);
        showlist->setObjectName("showlist");

        horizontalLayout->addWidget(showlist);

        adduser = new QPushButton(layoutWidget);
        adduser->setObjectName("adduser");

        horizontalLayout->addWidget(adduser);

        deletuser = new QPushButton(layoutWidget);
        deletuser->setObjectName("deletuser");

        horizontalLayout->addWidget(deletuser);

        changeuser = new QPushButton(layoutWidget);
        changeuser->setObjectName("changeuser");

        horizontalLayout->addWidget(changeuser);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        usermanagerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(usermanagerClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 748, 21));
        usermanagerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(usermanagerClass);
        mainToolBar->setObjectName("mainToolBar");
        usermanagerClass->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(usermanagerClass);
        statusBar->setObjectName("statusBar");
        usermanagerClass->setStatusBar(statusBar);

        retranslateUi(usermanagerClass);

        QMetaObject::connectSlotsByName(usermanagerClass);
    } // setupUi

    void retranslateUi(QMainWindow *usermanagerClass)
    {
        usermanagerClass->setWindowTitle(QCoreApplication::translate("usermanagerClass", "usermanager", nullptr));
        showlist->setText(QCoreApplication::translate("usermanagerClass", "\346\237\245\347\234\213", nullptr));
        adduser->setText(QCoreApplication::translate("usermanagerClass", "\345\242\236\345\212\240", nullptr));
        deletuser->setText(QCoreApplication::translate("usermanagerClass", "\345\210\240\351\231\244", nullptr));
        changeuser->setText(QCoreApplication::translate("usermanagerClass", "\346\233\264\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class usermanagerClass: public Ui_usermanagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMANAGER_H
