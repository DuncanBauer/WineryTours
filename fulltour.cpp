#include "fulltour.h"
#include "ui_fulltour.h"

FullTour::FullTour(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FullTour)
{

    ui->setupUi(this);
    tourWindow = new inTour();
}

FullTour::~FullTour()
{
    delete ui;
}

void FullTour::on_pushButton_clicked()
{
    tourWindow->show();
    this->close();
}
