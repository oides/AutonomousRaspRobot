#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "raspclient.h"
#include <QTime>

#include<QMessageBox>
#include<QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent*);
    void keyReleaseEvent(QKeyEvent*);

private:
    Ui::MainWindow *ui;
    RaspClient raspClient;
    QTime lastTime;
    QSet<QString> keysPressed;
    bool m_bFirstRelease;
};

#endif // MAINWINDOW_H
