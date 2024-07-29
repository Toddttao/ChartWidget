#include "login.h"

#include "regist_windows.h"
#include "Mysql/mysql.h"

login::login(mysql &db, QWidget *parent)
    : QDialog(parent)
	, db(&db)
	,registwindows(std::make_shared<regist_windows>(db,nullptr))
{
    ui.setupUi(this);
	this->setWindowTitle("login system");

	connect(ui.login, &QPushButton::clicked, this, &login::loginFunction);
	connect(ui.p_register, &QPushButton::clicked, this, &login::signFunction);
}

login::~login()
{}

//登录
void login::loginFunction()
{
	inUser = ui.username->text().trimmed();
	inpsw = ui.password->text().trimmed();
	if(db->logincheck(inUser,inpsw))
	{
		QMessageBox info;
		info.information(this, "tip", "success");
	}else
	{
		QMessageBox info;
		info.warning(this, "tip", "failed");
	}
}

//注册
void login::signFunction()
{
	registwindows->setWindowTitle("注册窗口");
	registwindows->show();
	this->close();
}

