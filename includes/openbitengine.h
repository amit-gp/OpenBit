#ifndef OPENBITENGINE_H
#define OPENBITENGINE_H

#include <libtorrent/session.hpp>
#include <libtorrent/torrent_handle.hpp>
#include <libtorrent/add_torrent_params.hpp>
#include <libtorrent/torrent_status.hpp>
#include <includes/settingshandler.h>
#include<alert_types.hpp>
#include <vector>
#include <QStandardPaths>
#include <QDir>
#include <QObject>
#include <QDebug>
#include <QFileInfo>
#include <QFile>
#include <QSettings>
#include <boost/assign/list_of.hpp>


class OpenBitEngine : public QObject {

    Q_OBJECT
public:
    explicit OpenBitEngine(QObject *parent = nullptr);    
    static void addNewAtp(const libtorrent::add_torrent_params &atp_object);    
    static SettingsHandler *session_user_settings;
private:

    static libtorrent::session main_session;
    static std::vector<libtorrent::torrent_handle> torrent_handles;
};

#endif // OPENBITENGINE_H
