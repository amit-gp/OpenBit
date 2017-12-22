#ifndef ADDTORRENTDIALOG_H
#define ADDTORRENTDIALOG_H

#include<boost/make_shared.hpp>
#include <libtorrent/add_torrent_params.hpp>
#include <libtorrent/error_code.hpp>
#include<includes/openbitmainwindow.h>
#include<includes/openbitmainwindow.h>
#include<libtorrent/torrent_info.hpp>
#include <includes/openbitengine.h>
#include<QFileDialog>
#include <QDialog>
#include<QStandardPaths>
#include <QDebug>
#include <includes/globalvariables.h>

namespace Ui {
class AddTorrentDialog;
}

class AddTorrentDialog : public QDialog {
    Q_OBJECT

public:
    explicit AddTorrentDialog(QDialog *parent = 0);
    inline const QString getFileExtension(const QString &file);
    inline const QString getFileFromPath(const QString &file);
    ~AddTorrentDialog();

private slots:
    void on_cancelPushButton_clicked();
    void on_addTorrentPushButton_clicked();
    void on_addTorrentTabWidget_currentChanged(int index);
    void on_chooseFileQushButton_clicked();    
    void on_magLinkLineEdit_textChanged(const QString &arg1);

private:
    Ui::AddTorrentDialog *ui;
    bool isDotTorrentValid = false;
    bool isMagLinkValid = false;
    bool isInfoHashValid = false;
    const int TORRENT_TAB = 0;
    const int MAGNETIC_LINK_TAB = 1;
    const int INFO_HASH_TAB = 2;
    int currentTab = 0;
    GlobalVariables *gv;
    QString torrentData;
    libtorrent::error_code ec;
    libtorrent::add_torrent_params atp_object;  //The atp object will store the torrent file information.
    inline void enableAcceptButton(bool value);
};

#endif // ADDTORRENTDIALOG_H
