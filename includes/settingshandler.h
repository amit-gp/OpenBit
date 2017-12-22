#ifndef SETTINGSHANDLER_H
#define SETTINGSHANDLER_H

#include <QObject>
#include <QSettings>
#include <QStandardPaths>
#include <QVariant>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <includes/globalvariables.h>

class SettingsHandler
{

public:
    SettingsHandler();
    QVariant getUserSettings(USER_SETTINGS_ENUM user_setting_val, const QVariant &defaultVal) const;
    void putUserSettingsValue(USER_SETTINGS_ENUM user_settings_val, const QVariant &val);


private:
    GlobalVariables *gv = GlobalVariables::Instance();
    QSettings *user_settings;
    void checkFilesOnDisk() const;  // Checks the files on the disk, creates the settings file if it does not exist
    void populateDefaults();  // Creates and Populates Deafualt values to non-existant settings.
};

#endif // SETTINGSHANDLER_H
