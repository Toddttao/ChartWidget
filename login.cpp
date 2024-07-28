#include "login.h"

login::login(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
	this->setWindowTitle("login system");

	connect(ui.login, &QPushButton::clicked, this, &login::loginFunction);
	connect(ui.p_register, &QPushButton::clicked, this, &login::signFunction);
}

login::~login()
{}

//µÇÂ¼
void login::loginFunction()
{
	inUser = ui.username->text();
	inpsw = ui.password->text();
	if(inUser == m_username && inpsw == m_password)
	{
		QMessageBox info;
		info.information(this, "tip", "success");
	}else
	{
		QMessageBox info;
		info.warning(this, "tip", "failed");
	}
}

//×¢²á
void login::signFunction()
{
	
}

