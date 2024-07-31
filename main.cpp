#include "login.h"
#include <QtWidgets/QApplication>
#include "Mysql/mysql.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::shared_ptr<mysql> db = std::make_shared<mysql>();
    login w(db);
    w.show();
    return a.exec();
}
