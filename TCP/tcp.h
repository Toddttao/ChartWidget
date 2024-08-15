#pragma once

#include "tcp_global.h"
#include "qtcpserver.h"
#include "qtcpsocket.h"



class TCP_EXPORT TCP : public QObject
{
    Q_OBJECT
public:
    TCP(QObject * parent = nullptr);
    ~TCP();

    void connectServer();

    void sendmessage(const QString& sMsg);

    void onConnected();

    void onDisconnected();

    void onError(QAbstractSocket::SocketError socketError);

    void onReadyRead();


private://客户端
    //客户端的socket
    QTcpSocket* pSocket = nullptr;
    //客户端的IP
    QString ip;
    //客户端的端口号
    unsigned int port;

    //读服务器
    //写服务器
};
