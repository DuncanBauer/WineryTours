#include "intour.h"
#include "ui_intour.h"
#include "mainwindow.h"

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
    numOfWineries = WineryList.size();
    currentWineryIndex = 0;
    currentWinery = &WineryVector.operator [](currentWineryIndex);
    SetWines();
    ui->winaryName->setText(currentWinery->getName());
}

inTour::~inTour()
{
    delete ui;
}

void inTour::on_nextButton_clicked()
{
    if(currentWineryIndex < WineryList.size() - 1)
    {
        currentWineryIndex++;
        currentWinery = &WineryList.operator [](currentWineryIndex);
        ui->winaryName->setText(currentWinery->getName());
        SetWines();
    }
    else
    {
        MainWindow* w = new MainWindow();
        w->show();
        this->close();
    }
}

void inTour::SetWines()
{
    ui->wineList->clear();
    for(int index = 0; index < currentWinery->getNumOfWines(); index++)
    {
        ui->wineList->addItem(currentWinery->getWine(index).GetName());
    }
}
