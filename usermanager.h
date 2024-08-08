#pragma once

#include <QMainWindow>
#include "ui_usermanager.h"
#include "QStandardItemModel"
#include "QContextMenuEvent"
#include "qdialog.h"
#include "QLineEdit"

class mysql;
class regist_windows;

class usermanager : public QMainWindow 
{
	Q_OBJECT

public:
	usermanager(std::shared_ptr<mysql> db , QWidget *parent = nullptr);
	~usermanager();

	void onClicked(const QModelIndex& index);

private slots:
	void init();
	void adduser();
	void deleteuser();
	void updateuser();

	//上下文事件（处理右键菜单）
	//void contextMenuEvent(QContextMenuEvent* event) override;
signals:
	void signal();

private:
	Ui::usermanagerClass ui;
	std::shared_ptr<mysql> db;

	QStandardItemModel* pModel;
	regist_windows* add = nullptr;

	QString name;
	QString powers;

	QDialog* input;
	QPushButton* updatebutton;
	QPushButton* cencelbutton;
};
