#include "mysql.h"

mysql::mysql():db(new QSqlDatabase(QSqlDatabase::addDatabase("ODBC")))
{
	
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