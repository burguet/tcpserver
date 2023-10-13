#include "InitiationQt.h"

InitiationQt::InitiationQt(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	socket = new QTcpSocket(this);
	QObject::connect(socket, SIGNAL(connected()), this, SLOT(onSocketConnected()));
	QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(onSocketDisconnected()));
	QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
	
	connect(ui.pushButtonCelcius, &QPushButton::clicked, this, &InitiationQt::onSendButtonCelciusClicked);
	connect(ui.pushButtonFahrenheit, &QPushButton::clicked, this, &InitiationQt::onSendButtonFahrenheitClicked);
	connect(ui.pushButtonHigrometrie, &QPushButton::clicked, this, &InitiationQt::onSendButtonHigrometrieClicked);


	server = new QTcpServer(this);
	QObject::connect(server, SIGNAL(newConnection()), this, SLOT(onServerNewConnection()));
	server->listen(QHostAddress::AnyIPv4, 4321);
}

void InitiationQt::onConnectButtonClicked(){
	QString ip = ui.IPLineEdit->text();
	QString port = ui.portLineEdit->text();


	bool ok;
	int portAsInt = port.toInt(&ok);
	if (ok)
	{
		socket->connectToHost(ip, portAsInt);
	}
}

void InitiationQt::onSocketConnected(){
	ui.connectionStatusLabel->setText("Status connexion : connecte !");
}

void InitiationQt::onSocketDisconnected(){
	ui.connectionStatusLabel->setText("Status connexion : Deconnecte !");
}

void InitiationQt::onSocketReadyRead(){
	QByteArray data = socket->read(socket->bytesAvailable());
	QString str(data);
	ui.label_1->setText("Le serveur dit : " + str);
}

void InitiationQt::onClientDisconnected(){
	QTcpSocket *obj = qobject_cast<QTcpSocket*>(sender());
	QObject::disconnect(obj, SIGNAL(readyRead()), this, SLOT(onClientReadyRead()));
	QObject::disconnect(obj, SIGNAL(disconnected()), this, SLOT(onClientDisconnected()));
	obj->deleteLater();
}

void InitiationQt::onSendButtonCelciusClicked() {
	if (socket->state() == QTcpSocket::ConnectedState) {
		QString message = ui.plainTextEditCFH->toPlainText();
		QString val = "Td" + message;
		QByteArray msg = val.toUtf8();
		socket->write(msg);
	}
}

void InitiationQt::onSendButtonFahrenheitClicked() {
	if (socket->state() == QTcpSocket::ConnectedState) {
		QString message = ui.plainTextEditCFH->toPlainText();
		QString val = "Tf" + message;
		QByteArray msg = val.toUtf8();
		socket->write(msg);
	}
}

void InitiationQt::onSendButtonHigrometrieClicked() {
	if (socket->state() == QTcpSocket::ConnectedState) {
		QString message = ui.plainTextEditCFH->toPlainText();
		QString val = "Hr" + message;
		QByteArray msg = val.toUtf8();
		socket->write(msg);
	}
}
