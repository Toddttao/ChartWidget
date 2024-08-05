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
    regist_windows(std::shared_ptr<mysql> db,QDialog* parent = nullptr);
    ~regist_windows();


    void disableButton();
signals:
    void registrationComplete();

private slots:
    void registInfo();
    void backrefistwindows();//返回登录窗口


private:
    Ui::Dialog ui;
    std::shared_ptr<mysql> db;
    QString user;
    QString pass;
};

