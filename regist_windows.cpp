#include "regist_windows.h"
#include "login.h"



//注册窗口构造函数
regist_windows::regist_windows(std::shared_ptr<mysql> db, QDialog* parent)
	:db(db)
{
	ui.setupUi(this);

	connect(ui.regist, &QPushButton::clicked, this,&regist_windows::registInfo);

}

regist_windows::~regist_windows()
{}

void regist_windows::backrefistwindows()
{
	auto loginwindows = new login(db, nullptr);

		loginwindows->show();
		this->close();
}

void regist_windows::registInfo()
{
    QString user = ui.username->text().trimmed();
    QString pass = ui.password->text().trimmed();

    if (user.isEmpty() || pass.isEmpty()) {
        QMessageBox::warning(this, "警告", "用户名和密码不能为空");
        return;
    }

    if (db->usernameisexist(user))
    {
        QMessageBox::warning(this, "提示", "用户名已存在");
        return;
    }

    if (db->regist(user, pass))
    {
        QMessageBox::information(this, "提示", "注册成功");
        emit registrationComplete();
        this->close();
    }
    else
    {
        QMessageBox::warning(this, "提示", "注册失败");
    }
}


