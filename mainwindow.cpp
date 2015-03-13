#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    shortWindow = new shortTour;
    customWindow = new CustomTour;
    fullWindow = new FullTour;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Custom_clicked()
{
    customWindow -> show();
}

void MainWindow::on_Short_clicked()
{
    shortWindow -> show();
}

void MainWindow::on_Full_clicked()
{
    fullWindow->show();
}
