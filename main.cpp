#include "login.h"
#include <QtWidgets/QApplication>
#include "Mysql/mysql.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mysql db;
    login w(db);
    w.show();
    return a.exec();
}
