#pragma once
#include <qobject.h>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/qsqlerror.h>
#include <QtSql/qsqldriver.h>
#include <QtSql/qsqlquery.h>
#include <qmessagebox.h>



class mysql :
    public QObject
{
    Q_OBJECT
public:
    mysql();
    ~mysql();

private:
    //���ݿ����ָ��
    QSqlDatabase* db;



private:
    void initdatabase();
};

