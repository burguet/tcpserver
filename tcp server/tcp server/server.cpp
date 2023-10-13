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
	QObject::disconnect(obj, SIGNAL(readyRead()), this, SLOT(onClientReadyRead()));
	QObject::disconnect(obj, SIGNAL(disconnected()), this, SLOT(onClientDisconnected()));
	obj->deleteLater();
}

void server::onClientReadyRead()
{
	QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
	QByteArray obj = socket->read(socket->bytesAvailable());
	QString str(obj);
	qDebug() << str;
	QStringRef subString(&str, 2, 2);

	int val = (rand() % 5700) - 2000;
	float rval = (float)val / (float)100;
	char c[2];
	strcpy(c, "");
	if (strlen(obj) == 5) {
		if (str.endsWith("?")) {
			if (str.startsWith("Td"))
			{
				qDebug() << "Temperature demandee en degres celsius";
				QString reponse = "Td";
				reponse.append(subString);
				if (rval > 0)
				{
					reponse += ",+";
					reponse += QString::number(rval);
				}
				else {
					reponse += ",";
					reponse += QString::number(rval);
				}
				socket->write(reponse.toUtf8());
			}
			if (str.startsWith("Tf"))
			{
				rval = (rval * 9.0 / 5.0) + 32;
				qDebug() << "Temperature demandee en Faraneite";
				QString reponse = "Tf";
				reponse.append(subString);
				if (rval > 0)
				{
					reponse += ",+";
					reponse += QString::number(rval);
				}
				else {
					reponse += ",-";
					rval *= -1;
					reponse += QString::number(rval);
				}

				socket->write(reponse.toUtf8());
			}

			if (str.startsWith("Hr")) {
				int val = (rand() % 999);
				float rval = (float)val / (float)10;
				qDebug() << "Taux d'humidité";
				QString reponse = "Hr";
				reponse.append(subString);

				reponse += ",";
				reponse += QString::number(rval);
				reponse += "%";

				socket->write(reponse.toUtf8());
			}
		}
	}
	else {
		socket->close();
	}
	
}

void server::onServerNewConnection() {
	/*ui.connectionStatusLabel->setText("Un client c'est connecté");*/
	qDebug() << "client connecté";
	QTcpSocket* client = tcpserver->nextPendingConnection();
	QObject::connect(client, SIGNAL(readyRead()), this, SLOT(onClientReadyRead()));
	QObject::connect(client, SIGNAL(disconnected()), this, SLOT(onClientDisconnected()));

}