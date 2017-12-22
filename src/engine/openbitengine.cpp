#include <includes/openbitengine.h>

// Declaring all the static constants.
libtorrent::session OpenBitEngine::main_session;
std::vector<libtorrent::torrent_handle> OpenBitEngine::torrent_handles;
SettingsHandler *OpenBitEngine::session_user_settings = new SettingsHandler();


OpenBitEngine::OpenBitEngine(QObject *parent) : QObject(parent){

    qDebug() << "OpenBitEngine Started..";
}

void OpenBitEngine::addNewAtp(const libtorrent::add_torrent_params &atp_object) {

    std::string str = atp_object.url;    
    libtorrent::torrent_handle th = main_session.add_torrent(atp_object);
    torrent_handles.push_back(main_session.add_torrent(atp_object));

    for (;;) {
      std::vector<libtorrent::alert*> alerts;
      main_session.pop_alerts(&alerts);

      for (libtorrent::alert const* a : alerts) {
        std::cout << a->message() << std::endl;
        if (libtorrent::alert_cast<libtorrent::torrent_finished_alert>(a)) {
          goto done;
        }
        if (libtorrent::alert_cast<libtorrent::torrent_error_alert>(a)) {
          goto done;
        }
        if (libtorrent::alert_cast<libtorrent::torrent_paused_alert>(a)) {
        }
      }
    }
    done:
    std::cout << "done, shutting down" << std::endl;
}
