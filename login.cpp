#include "login.h"

#include "regist_windows.h"
#include "Mysql/mysql.h"

login::login(std::shared_ptr<mysql> db, QWidget *parent)
    : db(db)
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
    QString inUser = ui.username->text().trimmed();
    QString inpsw = ui.password->text().trimmed();

    if (inUser.isEmpty() || inpsw.isEmpty()) {
        QMessageBox::warning(this, "警告", "用户名和密码不能为空");
        return;
    }

    if (db->logincheck(inUser, inpsw))
    {
        QMessageBox::information(this, "提示", "登录成功");
    }
    else
    {
        QMessageBox::warning(this, "提示", "登录失败");
    }
}

//注册
void login::signFunction()
{
    auto registwindow = new regist_windows(db, nullptr);
    registwindow->setAttribute(Qt::WA_DeleteOnClose);
    connect(registwindow, &regist_windows::registrationComplete, [this]() {
        login* newLoginWindow = new login(this->db);
        newLoginWindow->show();
        });
    registwindow->show();
    this->close();
}

