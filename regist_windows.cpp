#include "regist_windows.h"
#include "login.h"



//注册窗口构造函数
regist_windows::regist_windows(mysql&db, QDialog* parent)
	:loginwindows(std::make_shared<login>(db,nullptr))
	,_db(&db)
{
	ui.setupUi(this);

	connect(ui.back, &QPushButton::clicked, this, &regist_windows::backrefistwindows);
	connect(ui.regist, &QPushButton::clicked, this,&regist_windows::registInfo);

}

regist_windows::~regist_windows()
{}

void regist_windows::backrefistwindows()
{
	loginwindows->show();
	this->close();
}

void regist_windows::registInfo()
{
	user = ui.username->text().trimmed();
	pass = ui.password->text().trimmed();
	if (_db->usernameisexist(user))
	{
		QMessageBox::warning(this, "提示", "用户名重复");
		return;
	}
	if(_db->regist(user, pass))
	{
		QMessageBox::information(this, "提示", "注册成功");
		ui.username->clear();
		ui.password->clear();
		return;
	}else
	{
		QMessageBox::warning(this, "提示", "注册失败");
		ui.username->clear();
		ui.password->clear();
		return;
	}
}


