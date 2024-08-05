#include "usermanager.h"
#include "Mysql/mysql.h"
#include "memory"

usermanager::usermanager(std::shared_ptr<mysql> db,QWidget *parent)
	: QMainWindow(parent)
	, db(db)
	,pModel(new QStandardItemModel())

{
	ui.setupUi(this);

	

	connect(ui.showlist, &QPushButton::clicked, this, &usermanager::init);
}

usermanager::~usermanager()
{
	
}

//初始化标准model
void usermanager::init()
{
	QList<QString> userlist =  db->listusername();
	for(QString var : userlist)
	{
		QStandardItem* userItem = new QStandardItem(var);
		pModel->appendRow(userItem);
	}
	ui.tableView->setModel(pModel);
}
