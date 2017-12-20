#include "openbitmainwindow.h"
#include "ui_openbitmainwindow.h"

OpenBitMainWindow::OpenBitMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OpenBitMainWindow)
{
    ui->setupUi(this);
}

OpenBitMainWindow::~OpenBitMainWindow()
{
    delete ui;
}
