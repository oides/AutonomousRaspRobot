#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* e)
{
    QTime breakTime = this->lastTime.addMSecs(100);
    if (breakTime < QTime::currentTime())
    {
        keysPressed += e->text();
        m_bFirstRelease = true;
        this->lastTime = QTime::currentTime();
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent* e)
{
    if(m_bFirstRelease)
    {
        foreach (const QString &key, keysPressed)
        {
            ui->commandLabel->setText("Comando: " + key);
            cout << "EVENTO DEPOIS[" << key.toUtf8().constData() << "]" << endl;
            raspClient.sendMessage(key.toUtf8().constData());
        }
    }

    m_bFirstRelease = false;
    keysPressed -= e->text();
}
