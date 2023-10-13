#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_InitiationQt.h"
#include <qtcpsocket.h>
#include <qtcpserver.h>

class InitiationQt : public QMainWindow
{
	Q_OBJECT

public:
	InitiationQt(QWidget *parent = Q_NULLPTR);
	//~InitiationQt();

private:
	Ui::InitiationQtClass ui;
	QTcpSocket * socket;
	QTcpServer * server;
public slots:
	void onConnectButtonClicked();
	void onSocketConnected();
	void onSocketDisconnected();
	void onSocketReadyRead();
	void onClientDisconnected();
	void onSendButtonCelciusClicked();
	void onSendButtonFahrenheitClicked();
	void onSendButtonHigrometrieClicked();
};