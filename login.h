#pragma once

#include <QtWidgets/QDialog>
#include "ui_login.h"

class login : public QDialog
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private:
    Ui::loginClass ui;
};
