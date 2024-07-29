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

class mysql;


class login : public QDialog
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void loginFunction();//��¼�ۺ���
    void signFunction();//ע��ۺ���

private:
    Ui::loginClass ui;

    mysql* db;
    QString inUser;
    QString inpsw;
};
