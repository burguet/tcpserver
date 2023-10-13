/********************************************************************************
** Form generated from reading UI file 'InitiationQt.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INITIATIONQT_H
#define UI_INITIATIONQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InitiationQtClass
{
public:
    QWidget *centralWidget;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *IPLineEdit;
    QLineEdit *portLineEdit;
    QPushButton *pushButton_2;
    QLabel *connectionStatusLabel;
    QLabel *label_1;
    QLabel *label_chat;
    QPushButton *pushButtonCelcius;
    QPushButton *pushButtonFahrenheit;
    QPushButton *pushButtonHigrometrie;
    QPlainTextEdit *plainTextEditCFH;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *InitiationQtClass)
    {
        if (InitiationQtClass->objectName().isEmpty())
            InitiationQtClass->setObjectName(QString::fromUtf8("InitiationQtClass"));
        InitiationQtClass->resize(712, 554);
        centralWidget = new QWidget(InitiationQtClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 10, 47, 13));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 40, 47, 13));
        IPLineEdit = new QLineEdit(centralWidget);
        IPLineEdit->setObjectName(QString::fromUtf8("IPLineEdit"));
        IPLineEdit->setGeometry(QRect(70, 10, 113, 20));
        portLineEdit = new QLineEdit(centralWidget);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));
        portLineEdit->setGeometry(QRect(70, 40, 113, 20));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 70, 75, 23));
        connectionStatusLabel = new QLabel(centralWidget);
        connectionStatusLabel->setObjectName(QString::fromUtf8("connectionStatusLabel"));
        connectionStatusLabel->setGeometry(QRect(90, 60, 171, 41));
        label_1 = new QLabel(centralWidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(10, 180, 241, 51));
        label_chat = new QLabel(centralWidget);
        label_chat->setObjectName(QString::fromUtf8("label_chat"));
        label_chat->setGeometry(QRect(10, 160, 181, 16));
        pushButtonCelcius = new QPushButton(centralWidget);
        pushButtonCelcius->setObjectName(QString::fromUtf8("pushButtonCelcius"));
        pushButtonCelcius->setGeometry(QRect(20, 390, 75, 23));
        pushButtonFahrenheit = new QPushButton(centralWidget);
        pushButtonFahrenheit->setObjectName(QString::fromUtf8("pushButtonFahrenheit"));
        pushButtonFahrenheit->setGeometry(QRect(110, 390, 75, 23));
        pushButtonHigrometrie = new QPushButton(centralWidget);
        pushButtonHigrometrie->setObjectName(QString::fromUtf8("pushButtonHigrometrie"));
        pushButtonHigrometrie->setGeometry(QRect(200, 390, 75, 23));
        plainTextEditCFH = new QPlainTextEdit(centralWidget);
        plainTextEditCFH->setObjectName(QString::fromUtf8("plainTextEditCFH"));
        plainTextEditCFH->setGeometry(QRect(90, 300, 121, 81));
        InitiationQtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(InitiationQtClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 712, 21));
        InitiationQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(InitiationQtClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        InitiationQtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(InitiationQtClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        InitiationQtClass->setStatusBar(statusBar);

        retranslateUi(InitiationQtClass);
        QObject::connect(pushButton_2, SIGNAL(clicked()), InitiationQtClass, SLOT(onConnectButtonClicked()));

        QMetaObject::connectSlotsByName(InitiationQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *InitiationQtClass)
    {
        InitiationQtClass->setWindowTitle(QCoreApplication::translate("InitiationQtClass", "InitiationQt", nullptr));
        label_3->setText(QCoreApplication::translate("InitiationQtClass", "IP", nullptr));
        label_4->setText(QCoreApplication::translate("InitiationQtClass", "Port", nullptr));
        pushButton_2->setText(QCoreApplication::translate("InitiationQtClass", "Connexion", nullptr));
        connectionStatusLabel->setText(QCoreApplication::translate("InitiationQtClass", "status de connexion : deconnecte", nullptr));
        label_1->setText(QString());
        label_chat->setText(QCoreApplication::translate("InitiationQtClass", "Reception de message du serveur :", nullptr));
        pushButtonCelcius->setText(QCoreApplication::translate("InitiationQtClass", "\302\260C", nullptr));
        pushButtonFahrenheit->setText(QCoreApplication::translate("InitiationQtClass", "\302\260F", nullptr));
        pushButtonHigrometrie->setText(QCoreApplication::translate("InitiationQtClass", "Higrom\303\251trie", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InitiationQtClass: public Ui_InitiationQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITIATIONQT_H
