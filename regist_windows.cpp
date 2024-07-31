#include "regist_windows.h"
#include "login.h"



//注册窗口构造函数
regist_windows::regist_windows(std::shared_ptr<mysql> db, QDialog* parent)
	:db(db)
{
	ui.setupUi(this);

    //槽函数
	connect(ui.back, &QPushButton::clicked, this, &regist_windows::backrefistwindows);
	connect(ui.regist, &QPushButton::clicked, this,&regist_windows::registInfo);

}

regist_windows::~regist_windows()
{}

void regist_windows::backrefistwindows()
{
    //创建登录窗口
	auto loginwindows = new login(db, nullptr);

		loginwindows->show();//显示login窗口
		this->close();//关闭注册窗口
}

void regist_windows::registInfo()
{
    QString user = ui.username->text().trimmed();//获取文本框中的内容，trimmed()清除空格
    QString pass = ui.password->text().trimmed();

    if (user.isEmpty() || pass.isEmpty()) {//判断user pass文本框是否为空
        QMessageBox::warning(this, "警告", "用户名和密码不能为空");
        return;
    }

    if (db->usernameisexist(user))//用户名判重
    {
        QMessageBox::warning(this, "提示", "用户名已存在");
        return;
    }

    if (db->regist(user, pass))//注册
    {
        QMessageBox::information(this, "提示", "注册成功");
        emit registrationComplete();// emit 触发信号
        this->close();
    }
    else
    {
        QMessageBox::warning(this, "提示", "注册失败");
    }
}


