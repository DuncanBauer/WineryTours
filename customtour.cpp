#include "customtour.h"
#include "ui_customtour.h"

CustomTour::CustomTour(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomTour)
{
    ui->setupUi(this);
    tourWindow = new inTour();
}

CustomTour::~CustomTour()
{
    delete ui;
}

void CustomTour::on_pushButton_clicked()
{
    tourWindow->show();
    this->close();
}
