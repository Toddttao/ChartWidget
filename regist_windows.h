#pragma once
#include <QDialog>
#include "ui_regist_windows.h"
#include "Mysql/mysql.h"


class login;
class regist_windows :
    public QDialog
{
    Q_OBJECT

public:
    regist_windows(mysql& db,QDialog* parent = nullptr);
    ~regist_windows();

private slots:
    void registInfo();
    void backrefistwindows();//返回登录窗口

private:
    Ui::Dialog ui;
    std::shared_ptr<login> loginwindows;
    mysql *_db;
    QString user;
    QString pass;
};

