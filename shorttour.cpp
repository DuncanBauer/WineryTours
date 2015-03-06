#include "shorttour.h"
#include "ui_shorttour.h"

shortTour::shortTour(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shortTour)
{
    ui->setupUi(this);
    tourWindow = new inTour();
}

shortTour::~shortTour()
{
    delete ui;
}

void shortTour::on_pushButton_clicked()
{
    tourWindow->show();
    this->close();
}
