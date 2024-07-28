#pragma once
#include <qobject.h>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/qsqlerror.h>
#include <QtSql/qsqldriver.h>



class mysql :
    public QObject
{
    Q_OBJECT
public:
    mysql();
    ~mysql();

private:
    QSqlDatabase* db;

private:
    void initdatabase();
};

