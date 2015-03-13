#include "intour.h"
#include "ui_intour.h"

inTour::inTour(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inTour)
{
    ui->setupUi(this);
}

inTour::~inTour()
{
    delete ui;
}
