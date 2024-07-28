#pragma once

#include <QtWidgets/QDialog>
#include "ui_login.h"
#include <qmessagebox.h>

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

    QString m_username = "jack";
    QString m_password = "rols";

    QString inUser;
    QString inpsw;
};
