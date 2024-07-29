#include "mysql.h"

mysql::mysql()
	:db(new QSqlDatabase(QSqlDatabase::addDatabase("QODBC")))
	, query(new QSqlQuery(*db))
{
	initdatabase();
}
mysql::~mysql()
{
	if (db->isOpen())
	{
		db->close();
	}
	delete query;
	delete db;
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
	db->setDatabaseName("chart");
	//设置用户名
	db->setUserName("root");
	//设置用户密码
	db->setPassword("root");

	//判断数据库是否打开成功
	if (!db->open())
	{
		QSqlError er = db->lastError();
		QMessageBox::warning(nullptr, "数据库连接错误", "数据库连接错误，请重试");
	}
	else 
	{
		qDebug() << "连接数据库成功";
	}



}

bool mysql::usernameisexist(const QString& username)
{
	query->prepare("Select username from chart where username = :name");
	query->bindValue(":name", username);
	if (query->exec())
	{
		// 如果查询结果包含至少一行，则表示用户名已存在
		if (query->next())
		{
			return true;
		}
	}
	else
	{
		// 查询执行失败，可能发生了错误
		qDebug() << "Error executing query:" << query->lastError().text();
	}
	return false;
}

void mysql::regist(const QString& username, const QString& password)
{
	query->prepare("Insert into chart(username, password) values(:name, :psd) ");
	query->bindValue(":name", username);
	query->bindValue(":psd", password);
	if (query->exec())
	{
		qDebug() << "写入成功\n";
		return;
	}
	return;
}

bool mysql::logincheck(const QString& username, const QString& password)
{
	query->prepare("select * from chart where username = (:name) and password = (:password)");
	query->bindValue(":name", username);
	query->bindValue(":password", password);
	if (query->exec())
	{
		return true;

	}
	return false;
}
