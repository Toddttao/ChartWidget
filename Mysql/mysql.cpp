#include "mysql.h"

mysql::mysql():db(new QSqlDatabase(QSqlDatabase::addDatabase("ODBC")))
{
	
}
mysql::~mysql()
{
	
}

//初始化数据库
void mysql:: initdatabase()
{
	//初始化db，并添加ODBC数据库驱动
	//db = new QSqlDatabase(QSqlDatabase::addDatabase("QODBC"));

	//设置ip
	db->setHostName("localhost");
	//设置端口号
	db->setPort(3306);
	//设置连接数据库名
	db->setDatabaseName("NeveRF");
	//设置用户名
	db->setUserName("root");
	//设置用户密码
	db->setPassword("mysql.fan.1973");

	//判断数据库是否打开成功
	if (!db->open())
	{
		QSqlError er = db->lastError();
		QMessageBox::warning(nullptr, "数据库连接错误", "数据库连接错误，请重试");
	}
	else 
	{
		qDebug() << "连接数据库成功";
		
		//查询数据库对象指针
		QSqlQuery query(*db);

	}

}