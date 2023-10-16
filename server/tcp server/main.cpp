#include <QtCore/QCoreApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    server srv(&a);
    return a.exec();
}
