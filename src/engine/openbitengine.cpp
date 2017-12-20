#include "includes/openbitengine.h"

libtorrent::session OpenBitEngine::main_session;
const QString OpenBitEngine::OPENBIT_SETTINGS_INI_FILENAME = "/settings.ini";
const QString OpenBitEngine::OPENBIT_SETTINGS_DOC_NAME = "/OpenBit";
const QString OpenBitEngine::DEFAULT_DOWNLOAD_LOCATION = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);

OpenBitEngine::OpenBitEngine(QObject *parent) : QObject(parent)
{
    qDebug() << "OpenBitEngine Started..";
    loadUserSettings();
}

void OpenBitEngine::loadUserSettings()
{
    qDebug() << "Loading User Settings..";
    QString OpenBitDocPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + OPENBIT_SETTINGS_DOC_NAME;

    // Checking if the directory exists.
    qDebug() << OpenBitDocPath;
    if(!QDir(OpenBitDocPath).exists())
    {
        QDir().mkdir(OpenBitDocPath);
        qDebug() << "Directory not found, Created Directory.";
    }

    //Checking if the file exists.
    QFileInfo settingsFileInfo(OpenBitDocPath + OPENBIT_SETTINGS_INI_FILENAME);
    qDebug() << OpenBitDocPath + OPENBIT_SETTINGS_INI_FILENAME;
    if(!settingsFileInfo.exists())
    {
        QFile settingsFile(OpenBitDocPath + OPENBIT_SETTINGS_INI_FILENAME);
        if(!settingsFile.open(QFile::ReadWrite | QFile::Text))
            qDebug() << "Error opening settings file" << settingsFile.errorString();
        settingsFile.close();
        //Creating the file by calling open and then closing it.
        qDebug() << "Settings file not found, Created the file.";
    }

    //Loading the values from the settings.ini file
    QSettings mSettings(OpenBitDocPath + OPENBIT_SETTINGS_INI_FILENAME, QSettings::NativeFormat);
    if(!mSettings.contains("DOWNLOAD_LOCATION"))
    {
        mSettings.setValue("DOWNLOAD_LOCATION", DEFAULT_DOWNLOAD_LOCATION);
    }
}

void OpenBitEngine::addNewAtp(const libtorrent::add_torrent_params atp_object)
{
    main_session.add_torrent(atp_object);
}
