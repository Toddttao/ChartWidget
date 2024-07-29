#include "login.h"
#include "Mysql/mysql.h"

login::login(QWidget *parent)
    : QDialog(parent)
	, db(new mysql)
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
	inUser = ui.username->text();
	inpsw = ui.password->text();
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
	
}

