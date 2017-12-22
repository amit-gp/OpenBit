#include "includes/openbitmainwindow.h"
#include "includes/addtorrentdialog.h"
#include "ui_openbitmainwindow.h"

OpenBitMainWindow::OpenBitMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::OpenBitMainWindow) {
    ui->setupUi(this);
}

OpenBitMainWindow::~OpenBitMainWindow() {
    delete ui;
}

void OpenBitMainWindow::on_actionAdd_triggered() {
    AddTorrentDialog addDialog;
    addDialog.setModal(true);
    addDialog.exec();
}

void OpenBitMainWindow::on_actionSettings_triggered() {
    SettingsDialog settingsDialog;
    settingsDialog.setModal(true);
    settingsDialog.exec();
}
