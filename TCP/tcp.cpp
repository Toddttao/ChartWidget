#include "tcp.h"
#include "qdebug.h"

TCP::TCP(QObject* parent) : QObject(parent)
{
    pSocket = new QTcpSocket(this);
    connect(pSocket, &QTcpSocket::connected, this, &TCP::onConnected);
    connect(pSocket, &QTcpSocket::disconnected, this, &TCP::onDisconnected);
    connect(pSocket, &QTcpSocket::errorOccurred, this, &TCP::onError);
    connect(pSocket, &QTcpSocket::readyRead, this, &TCP::onReadyRead);
}

TCP::~TCP()
{
    pSocket->disconnectFromHost();
    pSocket->waitForDisconnected();
    delete pSocket;
}

void TCP::connectServer()
{
    pSocket->connectToHost(QHostAddress("127.0.0.1"), 9000);
}

void TCP::sendmessage(const QString& sMsg)
{
    if (pSocket->state() == QAbstractSocket::ConnectedState)
    {
        pSocket->write(sMsg.toUtf8());
        pSocket->waitForBytesWritten();
    }
    else
    {
        qDebug() << "Socket is not connected";
    }
}

void TCP::onConnected()
{
    qDebug() << "Connected to server";
}

void TCP::onDisconnected()
{
    qDebug() << "Disconnected from server";
}

void TCP::onError(QAbstractSocket::SocketError socketError)
{
    qDebug() << "Socket error:" << pSocket->errorString();
}

void TCP::onReadyRead()
{
    QByteArray data = pSocket->readAll();
    qDebug() << "Received data:" << data;
}
