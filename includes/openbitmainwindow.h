#ifndef OPENBITMAINWINDOW_H
#define OPENBITMAINWINDOW_H

#include <QMainWindow>
#include <includes/settingsdialog.h>

namespace Ui {
class OpenBitMainWindow;
}

class OpenBitMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OpenBitMainWindow(QWidget *parent = 0);
    ~OpenBitMainWindow();

private slots:
    void on_actionAdd_triggered();

    void on_actionSettings_triggered();

private:
    Ui::OpenBitMainWindow *ui;
};

#endif // OPENBITMAINWINDOW_H
