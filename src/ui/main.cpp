#include <includes/openbitmainwindow.h>
#include <QApplication>
#include <QDebug>
#include<includes/openbitengine.h>

int main(int argc, char *argv[]) {

    GlobalVariables *gv = GlobalVariables::Instance();
    qDebug() << "Inside Main";
    QApplication a(argc, argv);    
    qDebug() << "Created QApp";    
    // Starting the OpenBit Engine.
    OpenBitEngine openBitEngine;
    qDebug() << "Started Engine";
    QCoreApplication::setApplicationName(gv->PRODUCT_NAME);
    QCoreApplication::setOrganizationName(gv->COMPANY_NAME);
    QCoreApplication::setOrganizationDomain(gv->COMPANY_DOMAIN);
    qDebug() << "Set CoreApp properties";
    OpenBitMainWindow w;
    w.show();
    return a.exec();
}
