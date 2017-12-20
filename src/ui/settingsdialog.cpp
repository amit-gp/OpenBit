#include "includes/settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    QSettings mSettings(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + OpenBitEngine::OPENBIT_SETTINGS_DOC_NAME + OpenBitEngine::OPENBIT_SETTINGS_INI_FILENAME, QSettings::NativeFormat);
    ui->saveDirLineEdit->setText(mSettings.value("DOWNLOAD_LOCATION").toString());
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}


void SettingsDialog::on_choosePushButton_clicked()
{
    ui->saveDirLineEdit->setText(QFileDialog::getExistingDirectory(nullptr, tr("Open Download Directory"), QStandardPaths::writableLocation(QStandardPaths::HomeLocation), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks));
}

void SettingsDialog::on_savePushButton_3_clicked()
{
    QSettings mSettings(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + OpenBitEngine::OPENBIT_SETTINGS_DOC_NAME + OpenBitEngine::OPENBIT_SETTINGS_INI_FILENAME, QSettings::NativeFormat);
    mSettings.setValue("DOWNLOAD_LOCATION", ui->saveDirLineEdit->text());
    this->accept();
}

void SettingsDialog::on_cancelPushButton_clicked()
{
    this->reject();
}
