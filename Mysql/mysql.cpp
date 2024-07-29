#include "mysql.h"

mysql::mysql():db(new QSqlDatabase(QSqlDatabase::addDatabase("ODBC")))
{
	initdatabase();
}
mysql::~mysql()
{
	
}

//��ʼ�����ݿ�
void mysql:: initdatabase()
{
	//��ʼ��db�������ODBC���ݿ�����
	//db = new QSqlDatabase(QSqlDatabase::addDatabase("QODBC"));

	//����ip
	db->setHostName("localhost");
	//���ö˿ں�
	db->setPort(3306);
	//�����������ݿ���
	db->setDatabaseName("NeveRF");
	//�����û���
	db->setUserName("root");
	//�����û�����
	db->setPassword("mysql.fan.1973");

	//�ж����ݿ��Ƿ�򿪳ɹ�
	if (!db->open())
	{
		QSqlError er = db->lastError();
		QMessageBox::warning(nullptr, "���ݿ����Ӵ���", "���ݿ����Ӵ���������");
	}
	else 
	{
		qDebug() << "�������ݿ�ɹ�";
		
		//��ѯ���ݿ����ָ��
		QSqlQuery query(*db);
	}



}

bool mysql::usernameisexist(const QString& username)
{
	query->prepare("Select username from chart where username = :name");
	query->bindValue(":name", username);
	if (query->exec())
	{
		// �����ѯ�����������һ�У����ʾ�û����Ѵ���
		if (query->next())
		{
			return true;
		}
	}
	else
	{
		// ��ѯִ��ʧ�ܣ����ܷ����˴���
		qDebug() << "Error executing query:" << query->lastError().text();
	}
	return false;
}

void mysql::regist(const QString& username, const QString& password)
{
	query->prepare("Insert into chart(username, password) values(:name, :psd) ");
	query->bindValue(":name", username);
	query->bindValue(":psd", password);
	if (query->exec())
	{
		qDebug() << "д��ɹ�\n";
		return;
	}
	return;
}

bool mysql::logincheck(const QString& username, const QString& password)
{
	query->prepare("select * from chart where username = (:name) and password = (:password)");
	query->bindValue(":name", username);
	query->bindValue(":password", password);
	if (query->exec())
	{
		return true;

	}
	return false;
}
