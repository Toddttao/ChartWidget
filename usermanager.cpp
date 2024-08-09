#include "usermanager.h"
#include "Mysql/mysql.h"
#include "memory"
#include "regist_windows.h"

usermanager::usermanager(std::shared_ptr<mysql> db, QWidget* parent)
	: QMainWindow(parent)
	, db(db)
	, pModel(new QStandardItemModel())

{
	ui.setupUi(this);

	//power();

	connect(ui.showlist, &QPushButton::clicked, this, &usermanager::init);
	//connect(ui.showlist, &QPushButton::clicked, this, &usermanager::power);
	connect(ui.adduser, &QPushButton::clicked, this, &usermanager::adduser);
	connect(ui.deletuser, &QPushButton::clicked, this, &usermanager::deleteuser);
	connect(ui.tableView, &QTableView::clicked, this, &usermanager::onClicked);
	connect(this, &usermanager::signal, this, &usermanager::init);

	connect(ui.changeuser, &QPushButton::clicked, this, &usermanager::updateuser);

	/*connect(updatebutton, &QPushButton::clicked, this, &usermanager::updatebtn);
	connect(cencelbutton, &QPushButton::clicked, this, &usermanager::cencelbtn);*/
}

usermanager::~usermanager()
{
	
}

//添加用户
void usermanager::adduser()
{
	add = new regist_windows(db);
	//禁用按钮
	add->disableButton();
	add->show();
	//关联信号与槽（注册窗口关闭时，触发 signal()信号 ）
	connect(add, &regist_windows::registrationComplete, this, [&]()
		{
			emit signal();
		});
	
}

//删除用户
void usermanager::deleteuser()
{
	qDebug() << name;
	if(!name.isEmpty())
	{
 		db->deleteuser(name);
		emit signal();
	}

}

//修改用户
void usermanager::updateuser()
{
	//新建一个窗口
	input = new QDialog(nullptr);
	input->resize(400, 200);
	//创建一个输入框
	QLineEdit* lineInfo = new QLineEdit(nullptr);
	lineInfo->resize(200, 60);
	//设置这个对象的 父对象
	lineInfo->setParent(input);
	lineInfo->move(100, 30);
	//新建两个按钮
	updatebutton = new QPushButton("更改", this);
	cencelbutton = new QPushButton("取消", this);
	//设置两个按钮
	updatebutton->resize(140, 50);
	cencelbutton->resize(140, 50);
	updatebutton->move(50, 140);
	cencelbutton->move(210, 140);
	updatebutton->setParent(input);
	cencelbutton->setParent(input);

	//关联槽函数
	connect(updatebutton, &QPushButton::clicked, [&]()
		{
			QString userpower = lineInfo->text().trimmed();
			db->updateuser(userpower);
		});
	connect(cencelbutton, &QPushButton::clicked, [&]()
		{
			input->close();
		});

	input->show();
	connect(lineInfo, &QLineEdit::editingFinished, this, [&]()
		{
			powers = lineInfo->text().trimmed();
		});
	/*if(!powers.isEmpty())
	{
		db->updateuser(powers);
	}*/
}

//鼠标点击事件
void usermanager::onClicked(const QModelIndex& index)
{
	if (index.isValid())
	{
		//获取名称和权限
		name = index.sibling(index.row(), 0).data().toString();
		powers = index.sibling(index.row(), 1).data().toString();
		
	}
}



//void usermanager::contextMenuEvent(QContextMenuEvent* event)
//{
//	//从TabVIEW控件获取点击项的名称
//	QModelIndex index = ui.tableView->indexAt(event->pos());
//	if(!index.isValid())
//	{
//		return;
//	}
//	name = index.data().toString();
//
//}

//初始化标准model
void usermanager::init()
{
	//每次调用前清除控件数据 模型数据
	ui.tableView->clearSpans();
	pModel->clear();
	//获取用户名列表
	QList<QString> userlist =  db->listusername();
	//获取权限列表
	QList<QString> powerlist = db->listpower();
	//模型数据列表
	QList<QStandardItem*> power;
	//用户名列表按行添加至模型中
	for(QString var : userlist)
	{
		QStandardItem* userItem = new QStandardItem(var);
		pModel->appendRow(userItem);
		
	}
	//用户权限列表转换至模型对象指针后存放到模型数据列表
	for (QString var : powerlist)
	{
		QStandardItem* powerItem = new QStandardItem(var);
		power << powerItem;
	}
	//将数据添加至第二列  模型数据位置可以理解成数组下标
	pModel->insertColumn(1,power);
	ui.tableView->setModel(pModel);
}



