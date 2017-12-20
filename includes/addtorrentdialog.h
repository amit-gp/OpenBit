#ifndef ADDTORRENTDIALOG_H
#define ADDTORRENTDIALOG_H

#include <QDialog>
#include <libtorrent/add_torrent_params.hpp>
#include <libtorrent/error_code.hpp>

#include<QFileDialog>
#include<QStandardPaths>
#include<includes/openbitmainwindow.h>
#include<libtorrent/torrent_info.hpp>
#include<boost/make_shared.hpp>
#include <QDebug>
#include <includes/openbitengine.h>

namespace Ui {
class AddTorrentDialog;
}

class AddTorrentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddTorrentDialog(QDialog *parent = 0);
    inline QString getFileExtension(const QString &file);
    inline QString getFileFromPath(const QString &file);
    ~AddTorrentDialog();

private slots:
    void on_cancelPushButton_clicked();

    void on_addTorrentPushButton_clicked();

    void on_addTorrentTabWidget_currentChanged(int index);

    void on_chooseFileQushButton_clicked();

    void on_magLinkTextEdit_textChanged();

private:
    Ui::AddTorrentDialog *ui;
    bool isDotTorrentValid = false;
    bool isMagLinkValid = false;
    bool isInfoHashValid = false;
    const int TORRENT_TAB = 0;
    const int MAGNETIC_LINK_TAB = 1;
    const int INFO_HASH_TAB = 2;
    int currentTab = 0;
    QString torrentData;
    libtorrent::error_code ec;
    libtorrent::add_torrent_params atp_object;  //The atp object will store the torrent file information.

    inline void enableAcceptButton(bool value);
};

#endif // ADDTORRENTDIALOG_H
