#include "mysql.h"

mysql::mysql()
{
	
}
mysql::~mysql()
{
	
}

//��ʼ�����ݿ�
void mysql:: initdatabase()
{
	//��ʼ��db�������ODBC���ݿ�����
	db = new QSqlDatabase(QSqlDatabase::addDatabase("QODBC"));

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



}