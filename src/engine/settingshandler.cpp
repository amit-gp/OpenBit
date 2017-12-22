#include "includes/settingshandler.h"

SettingsHandler::SettingsHandler() {

       user_settings = new QSettings(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + gv->OPENBIT_SETTINGS_DOC_NAME + gv->OPENBIT_SETTINGS_INI_FILENAME, QSettings::NativeFormat);
       qDebug() << QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + gv->OPENBIT_SETTINGS_DOC_NAME;
       // First check and create the files on disk. Then, populate them.
       checkFilesOnDisk();
       populateDefaults();
   }

 void SettingsHandler::checkFilesOnDisk() const {

    // Checking if the directory exists.
    if(!QDir(gv->OPENBIT_SETTINGS_DOC_FULLPATH).exists()) {
        QDir().mkdir(gv->OPENBIT_SETTINGS_DOC_FULLPATH);
    }

    QFileInfo settingsFileInfo(gv->OPENBIT_SETTINGS_DOC_FULLPATH + gv->OPENBIT_SETTINGS_INI_FILENAME);
    //Creating the file by calling open and then closing it.
    if(!settingsFileInfo.exists()) { //Checking if the file exists.
        QFile settingsFile(gv->OPENBIT_SETTINGS_DOC_FULLPATH + gv->OPENBIT_SETTINGS_INI_FILENAME);
        if(!settingsFile.open(QFile::ReadWrite | QFile::Text))
            qDebug() << "Error opening settings file" << settingsFile.errorString();
        settingsFile.close();
    }
}

void SettingsHandler::populateDefaults() {

    //Loading the values from the settings.ini file
    if(!user_settings->contains(gv->userSettingsNameMap.at(DOWNLOAD_LOCATION))) {
        qDebug() << "Writing to ini file...";
        user_settings->setValue(gv->userSettingsNameMap.at(DOWNLOAD_LOCATION), gv->defaultUserSettingsValueMap.at(DOWNLOAD_LOCATION));
        user_settings->sync();
    }    
}

QVariant SettingsHandler::getUserSettings(USER_SETTINGS_ENUM user_setting_val, const QVariant &defVal) const {
    QVariant result =  user_settings->value(gv->userSettingsNameMap.at(user_setting_val), defVal);
    user_settings->sync();
    return result;
}

void SettingsHandler::putUserSettingsValue(USER_SETTINGS_ENUM user_settings_val, const QVariant &val) {

    user_settings->setValue(gv->userSettingsNameMap.at(user_settings_val), val);
    user_settings->sync();
}
