#include "server.h"

server::server(QObject* parent) 
    : QObject(parent)
{
    tcpserver = new QTcpServer(this);
    QObject::connect(tcpserver, SIGNAL(newConnection()), this, SLOT(onServerNewConnection()));
    tcpserver->listen(QHostAddress::AnyIPv4, 4321);
}

server::~server()
{
}

void server::onClientDisconnected()
{
    QTcpSocket* obj = qobject_cast<QTcpSocket*>(sender());
    QObject::disconnect(obj, SIGNAL(readyRead()), this, SLOT(onClientReadyRead));
    QObject::disconnect(obj, SIGNAL(disconnected()), this, SLOT(onClientDisconnected));
    obj->deleteLater();
}

void server::onClientReadyRead()
{
    QTcpSocket* obj = qobject_cast<QTcpSocket*>(sender());
}

void server::onServerNewConnection() {
   /* ui.connectionStatusLabel->setText("Un client c'est connecté");*/
    QTcpSocket* client = tcpserver->nextPendingConnection();
    QObject::connect(client, SIGNAL(readyRead()), this, SLOT(onClientReadyRead()));
    QObject::connect(client, SIGNAL(readyRead()), this, SLOT(onClientDisconnected()));
    
}