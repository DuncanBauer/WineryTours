#include "adminportal.h"
#include "ui_adminportal.h"

AdminPortal::AdminPortal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminPortal)
{
    ui->setupUi(this);
}

AdminPortal::~AdminPortal()
{
    delete ui;
}
