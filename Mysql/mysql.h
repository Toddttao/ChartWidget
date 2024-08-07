#pragma once
#include <qobject.h>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/qsqlerror.h>
#include <QtSql/qsqldriver.h>
#include <QtSql/qsqlquery.h>
#include <qmessagebox.h>
#include <QList>



#ifdef DATABASEMANAGER_EXPORTS
#define DATABASEMANAGER_API __declspec(dllexport)
#else
#define DATABASEMANAGER_API __declspec(dllimport)
#endif

class DATABASEMANAGER_API mysql :
    public QObject
{
    Q_OBJECT
public:
    mysql();
    ~mysql();


private:
    //数据库对象指针
    QSqlDatabase* db;

    //查询数据库对象指针
    QSqlQuery* query;

public:

    bool isConnected() const;
    //初始化数据库
    void initdatabase();
    //用户重名验证
    bool usernameisexist(const QString& username);
    //用户注册
    bool regist(const QString& username, const QString& password);
    //登录验证
    bool logincheck(const QString& username, const QString& password);
    //列出所有用户
    QList<QString> listusername()const;
    //列出用户权限
    QList<QString> listpower()const;
    //增加用户
    void adduser(const QString& username, const QString& password);

    //删除用户
    void deleteuser(QString& username);

    //修改用户信息
    void updateuser(QString& username);

};

