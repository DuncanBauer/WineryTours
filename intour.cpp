#include "intour.h"
#include "ui_intour.h"

inTour::inTour(QWidget *parent) :QWidget(parent),
ui(new Ui::inTour)
{

    ui->setupUi(this);
}

inTour::inTour(QWidget *parent, vector<Winery> WineryVector) :
    QWidget(parent),
    ui(new Ui::inTour)
{
    ui->setupUi(this);
    WineryList = WineryVector;
    ui->wineList->addItem(WineryVector.operator[](0).getName());


}

inTour::~inTour()
{
    delete ui;
}
