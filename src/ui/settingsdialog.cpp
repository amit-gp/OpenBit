#include "includes/settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) : QDialog(parent), ui(new Ui::SettingsDialog) {
    ui->setupUi(this);
    gv = GlobalVariables::Instance();
    ui->saveDirLineEdit->setText(OpenBitEngine::session_user_settings->getUserSettings(DOWNLOAD_LOCATION, QVariant(gv->defaultUserSettingsValueMap.at(DOWNLOAD_LOCATION))).toString());
}

SettingsDialog::~SettingsDialog() {
    delete ui;
}

void SettingsDialog::on_choosePushButton_clicked() {
    ui->saveDirLineEdit->setText(QFileDialog::getExistingDirectory(nullptr, tr("Open Download Directory"), QStandardPaths::writableLocation(QStandardPaths::HomeLocation), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks));
}

void SettingsDialog::on_savePushButton_3_clicked() {
    OpenBitEngine::session_user_settings->putUserSettingsValue(DOWNLOAD_LOCATION, QVariant(ui->saveDirLineEdit->text()));
    this->accept();
}

void SettingsDialog::on_cancelPushButton_clicked() {
    this->reject();
}
