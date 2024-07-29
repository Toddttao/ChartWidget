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
class regist_windows;

class login : public QDialog
{
    Q_OBJECT

public:
    login(mysql &db,QWidget *parent = nullptr);
    ~login();

private slots:
    void loginFunction();//登录槽函数
    void signFunction();//注册槽函数

private:
    Ui::loginClass ui;

    mysql *db;
    QString inUser;
    QString inpsw;
    std::shared_ptr<regist_windows> registwindows;
};
