#pragma once
#include <qtcpserver.h>
#include <qobject.h>
#include <qtcpsocket.h>
class server : public QObject
{
	Q_OBJECT
		
public:
	server(QObject* parent = Q_NULLPTR);
	virtual ~server();

private :
	QTcpServer* tcpserver;

public slots:
	void onServerNewConnection();
	void onClientDisconnected();
	void onClientReadyRead();
};

