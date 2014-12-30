#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "raspclient.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_controlInput_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    RaspClient raspClient;
};

#endif // MAINWINDOW_H
