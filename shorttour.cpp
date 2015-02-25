#include "shorttour.h"
#include "ui_shorttour.h"

shortTour::shortTour(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shortTour)
{
    ui->setupUi(this);
}

shortTour::~shortTour()
{
    delete ui;
}
