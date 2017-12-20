#ifndef OPENBITENGINE_H
#define OPENBITENGINE_H

#include <QObject>
#include <vector>
#include <libtorrent/session.hpp>
#include <libtorrent/torrent_handle.hpp>
#include <libtorrent/add_torrent_params.hpp>
#include <QStandardPaths>
#include <QDir>
#include <QDebug>
#include <QFileInfo>
#include <QFile>
#include <QSettings>

class OpenBitEngine : public QObject
{
    Q_OBJECT
public:
    explicit OpenBitEngine(QObject *parent = nullptr);    
    static void addNewAtp(const libtorrent::add_torrent_params atp_object);

    static const QString OPENBIT_SETTINGS_DOC_NAME;
    static const QString OPENBIT_SETTINGS_INI_FILENAME;
    static const QString DEFAULT_DOWNLOAD_LOCATION;

signals:

public slots:

private:

    static libtorrent::session main_session;
    static std::vector<libtorrent::torrent_handle> torrent_handles;
    void loadUserSettings();
};

#endif // OPENBITENGINE_H
