#include "fulltour.h"
#include "ui_fulltour.h"

FullTour::FullTour(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FullTour)
{
    ui->setupUi(this);
}

FullTour::~FullTour()
{
    delete ui;
}
