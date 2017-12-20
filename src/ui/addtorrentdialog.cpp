#include "includes/addtorrentdialog.h"
#include "ui_addtorrentdialog.h"

AddTorrentDialog::AddTorrentDialog(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::AddTorrentDialog)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    ui->addTorrentPushButton->setEnabled(false);
    ui->fileChosenLabel->setVisible(false);
    ui->fileChosenLabel->setWordWrap(true);
}

AddTorrentDialog::~AddTorrentDialog()
{
    delete ui;
}

void AddTorrentDialog::on_cancelPushButton_clicked()
{
    this->reject();
}

void AddTorrentDialog::on_addTorrentPushButton_clicked()
{
    switch (currentTab) {
        case 0:
            //.Torrent tab.
            atp_object.ti = boost::make_shared<libtorrent::torrent_info>(torrentData.toStdString(), boost::ref(ec), 0);
            break;

        case 1:
            //Mag Link Tab tab.
            atp_object.url = ui->magLinkTextEdit->toPlainText().toStdString();

            break;

        case 2:
            //Info Hash Tab tab.
            break;

        default:
            break;
    }

    OpenBitEngine::addNewAtp(atp_object);
    this->accept();
}

void AddTorrentDialog::on_addTorrentTabWidget_currentChanged(int index)
{
    currentTab = index;

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

QString AddTorrentDialog::getFileExtension(const QString &file)
{
    return file.right(file.length() - file.lastIndexOf("."));
}

QString AddTorrentDialog::getFileFromPath(const QString &file)
{
    return file.right(file.length() - file.lastIndexOf('/'));
}

void AddTorrentDialog::enableAcceptButton(bool value)
{
    ui->addTorrentPushButton->setEnabled(value);
}

void AddTorrentDialog::on_chooseFileQushButton_clicked()
{
    torrentData = QFileDialog::getOpenFileName(nullptr, QString("Choose Torrent"), QString(), tr("Torrent Files (*.torrent)"));
    ui->fileChosenLabel->setVisible(true);
    // Torrent can be added if the file extension is a .torrent
    ui->fileChosenLabel->setText(getFileFromPath(torrentData));
    if(QString::compare(getFileExtension(torrentData), ".torrent") == 0){
        isDotTorrentValid = true;
        enableAcceptButton(true);
    }
}


void AddTorrentDialog::on_magLinkTextEdit_textChanged()
{
    //Enabling the add button for the mag link if there is any text in the text edit.
    enableAcceptButton(true);
    isMagLinkValid = true;
    if(ui->magLinkTextEdit->toPlainText().isEmpty()){
        enableAcceptButton(false);
        isMagLinkValid = false;
        return;
    }
}
