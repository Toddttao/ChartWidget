#pragma once

#include <QtWidgets/QDialog>
#include "ui_login.h"
#include <qmessagebox.h>
#include "Mysql/mysql.h"

#ifdef MYLIBRARY_EXPORTS
#define MYLIBRARY_API __declspec(dllexport)
#else
#define MYLIBRARY_API __declspec(dllimport)
#endif

class login : public QDialog
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void loginFunction();//µÇÂ¼²Ûº¯Êý
    void signFunction();//×¢²á²Ûº¯Êý

private:
    Ui::loginClass ui;

    QString m_username = "jack";
    QString m_password = "rols";

    QString inUser;
    QString inpsw;
};
