#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    WineryVector = ReadFile("wineries.txt");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Custom_clicked()
{
    customWindow = new CustomTour(NULL, WineryVector);
    customWindow->show();
    this->close();
}

void MainWindow::on_Short_clicked()
{
    shortWindow = new shortTour(NULL, WineryVector);
    shortWindow->show();
    this->close();
}

void MainWindow::on_Admin_clicked()
{
    adminWindow = new AdminPortal(NULL, WineryVector);
    adminWindow->show();
    this->close();
}
