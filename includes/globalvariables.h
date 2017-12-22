#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H

#include <QObject>
#include <boost/assign/list_of.hpp>
#include <boost/unordered_map.hpp>
#include <QStandardPaths>

enum USER_SETTINGS_ENUM{

    DOWNLOAD_LOCATION
};

class GlobalVariables : public QObject
{
    Q_OBJECT
public:

    static GlobalVariables* Instance();
    const QString COMPANY_NAME = "thebournegenius_software";
    const QString PRODUCT_NAME = "OpenBit";
    const QString COMPANY_DOMAIN = "github.com/thebournegenius/OpenBit";
    const QString OPENBIT_SETTINGS_INI_FILENAME = "/settings.ini";
    const QString OPENBIT_SETTINGS_DOC_NAME = "/OpenBit";
    const QString DEFAULT_DOWNLOAD_LOCATION = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
    const QString OPENBIT_SETTINGS_DOC_FULLPATH = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + OPENBIT_SETTINGS_DOC_NAME;

    // Unordered Maps that will contain the settings and default values based on the USER_SETTINGS_ENUM
    const boost::unordered_map<USER_SETTINGS_ENUM, QString> userSettingsNameMap = boost::assign::map_list_of
        (DOWNLOAD_LOCATION, "DOWNLOAD_LOCATION");
    const boost::unordered_map<USER_SETTINGS_ENUM,const QString> defaultUserSettingsValueMap = boost::assign::map_list_of
        (DOWNLOAD_LOCATION, OPENBIT_SETTINGS_DOC_FULLPATH);

private:
    static GlobalVariables* mInstance;
    explicit GlobalVariables(QObject *parent = nullptr) {}
    GlobalVariables(GlobalVariables const&){}

};

#endif // GLOBALVARIABLES_H
