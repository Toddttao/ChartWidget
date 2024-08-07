#pragma once

#include <QMainWindow>
#include "ui_usermanager.h"
#include "QStandardItemModel"
#include "QContextMenuEvent"

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
	/*void power();*/
	void adduser();
	void deleteuser();

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
};
