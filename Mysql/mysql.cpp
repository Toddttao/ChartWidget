#include "mysql.h"

mysql::mysql()
{
	
}
mysql::~mysql()
{
	
}

//初始化数据库
void mysql:: initdatabase()
{
	//初始化db，并添加ODBC数据库驱动
	db = new QSqlDatabase(QSqlDatabase::addDatabase("QODBC"));

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



}