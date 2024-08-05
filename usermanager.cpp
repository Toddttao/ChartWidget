#include "usermanager.h"
#include "Mysql/mysql.h"

usermanager::usermanager(std::make_shared<mysql> db,QWidget *parent)
	: QMainWindow(parent)
	, db(db)
{
	ui.setupUi(this);
}

usermanager::~usermanager()
{
	
}
