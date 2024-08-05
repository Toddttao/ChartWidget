#pragma once

#include <QtWidgets/QDialog>
#include "ui_login.h"
#include <qmessagebox.h>
#include "Mysql/mysql.h"
#include <qstandarditemmodel.h>

#ifdef MYLIBRARY_EXPORTS
#define MYLIBRARY_API __declspec(dllexport)
#else
#define MYLIBRARY_API __declspec(dllimport)
#endif

class mysql;
class regist_windows;
class usermanager;
class login : public QDialog
{
    Q_OBJECT

public:
    login(std::shared_ptr<mysql> db,QWidget *parent = nullptr);
    ~login();

private slots:
    void loginFunction();//登录槽函数
    void signFunction();//注册槽函数

private:
    Ui::loginClass ui;

    std::shared_ptr<mysql> db;
    QString inUser;
    QString inpsw;
    std::weak_ptr<regist_windows> registwindows;
    usermanager* _pmanager;
};
