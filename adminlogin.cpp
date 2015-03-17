#include "adminlogin.h"
#include "ui_adminlogin.h"
#include "mainwindow.h"

adminLogin::adminLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminLogin)
{
    ui->setupUi(this);
    this->setWindowTitle("Admin Login");
}

adminLogin::~adminLogin()
{
    delete ui;
}

void adminLogin::on_pushButton_2_clicked()
{
    MainWindow* w = new MainWindow();
    w->show();
    this->close();
}

void adminLogin::on_login_clicked()
{
    QString password = ui->password->text();

    if(password == "holyJamoli")
    {
        AdminPortal* w = new AdminPortal();
        w->show();
        this->close();
    }
    else
    {
        responseWindow* w = new responseWindow(NULL, "Incorrect Password", "The password you have entered is incorrect");
        w->show();
    }
}
