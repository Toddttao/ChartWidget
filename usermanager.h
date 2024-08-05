#pragma once

#include <QMainWindow>
#include "ui_usermanager.h"
#include "QStandardItemModel"

class mysql;

class usermanager : public QMainWindow
{
	Q_OBJECT

public:
	usermanager(std::shared_ptr<mysql> db , QWidget *parent = nullptr);
	~usermanager();

private:
	Ui::usermanagerClass ui;
	std::shared_ptr<mysql> db;
};
