#pragma once
#include <qobject.h>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/qsqlerror.h>
#include <QtSql/qsqldriver.h>
#include <QtSql/qsqlquery.h>
#include <qmessagebox.h>



#ifdef DATABASEMANAGER_EXPORTS
#define DATABASEMANAGER_API __declspec(dllexport)
#else
#define DATABASEMANAGER_API __declspec(dllimport)
#endif

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

    //��ѯ���ݿ����ָ��
    QSqlQuery* query;

private:
    void initdatabase();
};

