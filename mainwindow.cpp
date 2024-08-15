#include "mainwindow.h"
#include "login.h"
#include "TCP/tcp.h"

MainWindow::MainWindow(std::shared_ptr<mysql> db,QObject *parent)
	:db(db)
	, pTCP(std::make_unique<TCP>())
{
	ui.setupUi(this);

	pTCP->connectServer();

	connect(ui.send, &QPushButton::clicked, this, &MainWindow::sendButton);
	connect(ui.back, &QPushButton::clicked, this, &MainWindow::backLoginWindows);
}

MainWindow::~MainWindow()
{}

//返回登录窗口
void MainWindow::backLoginWindows()
{
	auto* loginWidget = new login(db,nullptr);//新创建一个登录窗口
	loginWidget->setAttribute(Qt::WA_DeleteOnClose);
	loginWidget->setWindowTitle("登录界面");
	loginWidget->show();
	this->close();
}

//发送按钮
void MainWindow::sendButton()
{
	sendInfo = ui.sendtext->toPlainText();//发送文本框
	pTCP->sendmessage(sendInfo);
	ui.recvtext->append(sendInfo);//将需要发送的内容显示在对话框
	ui.sendtext->clear();//清空发送文本框中的内容
	qDebug() << sendInfo;

}


