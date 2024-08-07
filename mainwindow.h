#pragma once

#include "ui_mainWindows.h"
#include <QMainWindow>
#include "Mysql/mysql.h"

class MainWindow  : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(std::shared_ptr<mysql> db,QObject *parent = nullptr);
	~MainWindow();

private slots:
	void sendButton();//发送按钮
	void backLoginWindows();//返回登录窗口

private:
	Ui::Form ui;
	std::shared_ptr<mysql> db;

	QString sendInfo;
	QString recvInfo;
};
