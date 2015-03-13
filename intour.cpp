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
    numOfWineries = WineryVector.size();
    currentWineryIndex = 0;
    currentWinery = &WineryVector.operator [](currentWineryIndex);

    for(int index = 0; index < currentWinery->getNumOfWines(); index++)
    {
        ui->wineList->addItem(currentWinery->getWine(index).GetName());
    }

}

inTour::~inTour()
{
    delete ui;
}

void inTour::on_nextButton_clicked()
{
    currentWineryIndex++;
}
