#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    windowAbout.close();
    windowWave.close();
    delete ui;
}


void MainWindow::on_actionWave_Viewer_triggered()
{
    if(windowAbout.isHidden())
        windowWave.show();
    else
        return;
}


void MainWindow::on_actionAbout_triggered()
{
    if(windowAbout.isHidden())
        windowAbout.show();
    else
        return;
}


void MainWindow::on_pushButton_clicked()
{
    if(windowAbout.isHidden())
        windowWave.show();
    else
        return;
}


void MainWindow::on_pushButton_2_clicked()
{
     if(windowAbout.isHidden())
        windowAbout.show();
    else
        return;
}

