#ifndef OPENBITMAINWINDOW_H
#define OPENBITMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class OpenBitMainWindow;
}

class OpenBitMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OpenBitMainWindow(QWidget *parent = 0);
    ~OpenBitMainWindow();

private:
    Ui::OpenBitMainWindow *ui;
};

#endif // OPENBITMAINWINDOW_H
