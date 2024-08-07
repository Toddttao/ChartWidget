#include "mysql.h"

mysql::mysql()//mysql构造函数
	:db(new QSqlDatabase(QSqlDatabase::addDatabase("QODBC")))//数据库初始化（通过OBDC驱动连接mysql数据库）
	, query(new QSqlQuery(*db))//查询指针初始化
{
	initdatabase();
	if (!db || !isConnected()) {
		QMessageBox::critical(nullptr, "错误", "数据库连接失败");
	}
	
}
mysql::~mysql()
{
	if (db->isOpen())//判断数据是否成功打开
	{
		db->close();//关闭数据库
	}
	delete query;//删除查询指针
	delete db;//删除数据库指针
}

bool mysql::isConnected() const
{
	return db->isOpen();
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
	//db->setPassword("mysql.fan.1973");
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

//用户名判重
bool mysql::usernameisexist(const QString& username)
{
	query->prepare("Select username from f_user where username = :name");
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

//用户注册
bool mysql::regist(const QString& username, const QString& password)
{
	//写sql语句  :name, :psd  占位符，其值通过 query->bindValue()绑定 
	query->prepare("Insert into f_user(username, password) values(:name, :psd) ");
	//绑定sql语句中的值
	query->bindValue(":name", username);
	query->bindValue(":psd", password);
	if (query->exec())//  query->exec()  执行sql语句
	{
		qDebug() << "写入成功\n";
		return true;
	}
	return false;
}

//登录判断用户名、密码是否正确


bool mysql::logincheck(const QString & username, const QString & password)
{
	query->prepare("SELECT * FROM f_user WHERE username = :name AND password = :password");
	query->bindValue(":name", username);
	query->bindValue(":password", password);

	qDebug() << "Executing login query for username:" << username;

	if (query->exec())
	{
		if (query->next())//  获取 query->exec() 执行的结果
		{
			qDebug() << "Login successful for user:" << username;
			return true;
		}
		else
		{
			qDebug() << "Login failed: No matching user found for username:" << username;
			return false;
		}
	}
	else
	{
		qDebug() << "Login query failed:" << query->lastError().text();// 获取最后的一个错误
		return false;
	}
}

//用户列表
QList<QString> mysql::listusername() const
{
	QList<QString> usernamelist;
	query->prepare("select * from f_user ");

	if(!query->exec())
	{
		QMessageBox::warning(nullptr, "提示", "执行失败");
		return usernamelist;
	}

	while (query->next())
	{
		//获取查询到的 记录 的数据（值）
		QString username = query->value("username").toString();
		//将 数据 添加到usernamelist中
		usernamelist.append(username);
	}
	//返回list数据
	return  usernamelist;
}

//列出用户权限
QList<QString> mysql::listpower() const
{
	QList<QString> listpower ;
	query->prepare("select * from f_user");
	if(!query->exec())
	{
		QMessageBox::warning(nullptr, "提示", "执行失败");
		return listpower;
	}
	while (query->next())
	{
		//获取查询到的数据
		bool userpower = query->value("power").toBool();
		if(userpower)
		{
			QString power = "管理员";
			listpower.append(power);
		}
		else
		{
			QString power = "普通用户";
			listpower.append(power);
		}
	}
	return listpower;
}

//添加用户
void mysql::adduser(const QString& username, const QString& password)
{
	regist(username, password);
}

//删除用户
void mysql::deleteuser(QString& username)
{
	query->prepare("delete from f_user where username = :username");
	query->bindValue(":username",username);
	if(query->exec())
	{

		if (query->next())//  获取 query->exec() 执行的结果
		{
			qDebug() << "Login successful for user:" << username;
			return ;
		}
		else
		{
			qDebug() << "Login failed: No matching user found for username:" << username;
			return;
		}
	}
	QMessageBox::warning(nullptr, "提示", "执行失败");
}

//修改用户权限
void mysql::updateuser(QString& userpower)
{
	query->prepare("update f_user set power = :userpower");
	query->bindValue(":userpower", userpower);
	if(!query->exec())
	{
		QMessageBox::warning(nullptr, "提示", "用户权限异常");
		return;
	}

	if(!query->next())
	{
		QMessageBox::warning(nullptr, "提示", "修改失败");
		return;
	}
	//something wrong in here
}



