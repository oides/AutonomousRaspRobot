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

void MainWindow::on_controlInput_textChanged(const QString &arg1)
{
    if (!arg1.isEmpty())
    {
        ui->commandLabel->setText("Comando: " + arg1);
        ui->controlInput->setText("");
    }
}
