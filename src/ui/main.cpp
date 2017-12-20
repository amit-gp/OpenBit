#include <includes/openbitmainwindow.h>
#include <QApplication>
#include<includes/openbitengine.h>

#define COMPANY_NAME "thebournegenius_software"
#define PRODUCT_NAME "OpenBit"
#define COMPANY_DOMAIN "github.com/thebournegenius/OpenBit"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setApplicationName(PRODUCT_NAME);
    QCoreApplication::setOrganizationName(COMPANY_NAME);
    QCoreApplication::setOrganizationDomain(COMPANY_DOMAIN);

    // Starting the OpenBit Engine.
    OpenBitEngine openBitEngine;

    OpenBitMainWindow w;
    w.show();

    return a.exec();
}
