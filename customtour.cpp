#include "customtour.h"
#include "ui_customtour.h"

CustomTour::CustomTour(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomTour)
{
    ui->setupUi(this);
}

CustomTour::~CustomTour()
{
    delete ui;
}
