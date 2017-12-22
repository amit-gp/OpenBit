#include "includes/addtorrentdialog.h"
#include "ui_addtorrentdialog.h"

AddTorrentDialog::AddTorrentDialog(QDialog *parent) : QDialog(parent), ui(new Ui::AddTorrentDialog) {
    ui->setupUi(this);
    this->setFixedSize(this->size());
    ui->addTorrentPushButton->setEnabled(false);
    ui->fileChosenLabel->setVisible(false);
    ui->fileChosenLabel->setWordWrap(true);
    gv = GlobalVariables::Instance();
}

AddTorrentDialog::~AddTorrentDialog() {
    delete ui;
}

void AddTorrentDialog::on_cancelPushButton_clicked() {
    this->reject();
}

void AddTorrentDialog::on_addTorrentPushButton_clicked() {

    switch (ui->addTorrentTabWidget->currentIndex()) {
        case 0:
            //.Torrent tab.    
            atp_object.ti = boost::make_shared<libtorrent::torrent_info>(torrentData.toStdString(), boost::ref(ec), 0);
            break;

        case 1:
            //Mag Link Tab tab.
            atp_object.url = ui->magLinkLineEdit->text().toStdString();            
            break;

        case 2:
            //Info Hash Tab tab.
            //TODO
            break;

        default:
            break;
    }    
    atp_object.save_path = OpenBitEngine::session_user_settings->getUserSettings(DOWNLOAD_LOCATION, QVariant(gv->defaultUserSettingsValueMap.at(DOWNLOAD_LOCATION))).toString().toStdString();
    OpenBitEngine::addNewAtp(atp_object);    
    this->accept();
}

void AddTorrentDialog::on_addTorrentTabWidget_currentChanged(int index) {

    switch (index) {
        case 0:
            //.Torrent tab clicked.
            if(isDotTorrentValid)
                enableAcceptButton(true);
            else
                enableAcceptButton(false);
            break;

        case 1:
            //Mag Link Tab tab clicked.
            if(isMagLinkValid)
                enableAcceptButton(true);
            else
                enableAcceptButton(false);
            break;

        case 2:
            //Info Hash Tab tab clicked.
            if(isInfoHashValid)
                enableAcceptButton(true);
            else
                enableAcceptButton(false);
            break;

        default:
            break;
    }
}

const QString AddTorrentDialog::getFileExtension(const QString &file) {
    return file.right(file.length() - file.lastIndexOf("."));
}

const QString AddTorrentDialog::getFileFromPath(const QString &file) {
    return file.right(file.length() - file.lastIndexOf('/'));
}

void AddTorrentDialog::enableAcceptButton(bool value) {
    ui->addTorrentPushButton->setEnabled(value);
}

void AddTorrentDialog::on_chooseFileQushButton_clicked() {

    torrentData = QFileDialog::getOpenFileName(nullptr, QString("Choose Torrent"), QString(), tr("Torrent Files (*.torrent)"));
    ui->fileChosenLabel->setVisible(true);    
    ui->fileChosenLabel->setText(getFileFromPath(torrentData));     // Torrent can be added if the file extension is a .torrent
    if(QString::compare(getFileExtension(torrentData), ".torrent") == 0){
        isDotTorrentValid = true;
        enableAcceptButton(true);
    }
}

void AddTorrentDialog::on_magLinkLineEdit_textChanged(const QString &arg1) {

    //Enabling the add button for the mag link if there is any text in the text edit.
    enableAcceptButton(true);
    isMagLinkValid = true;
    if(ui->magLinkLineEdit->text().isEmpty()){
        enableAcceptButton(false);
        isMagLinkValid = false;
        return;
    }
}
