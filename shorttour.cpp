#include "shorttour.h"
#include "ui_shorttour.h"

shortTour::shortTour(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shortTour)
{
    ui->setupUi(this);
}

shortTour::shortTour(QWidget *parent, vector<Winery> WineryVector) :
    QWidget(parent),
    ui(new Ui::shortTour)
{
    ui->setupUi(this);
    tourWindow = new inTour();

    Winery temp;
    for(int i = 0; i < WineryVector.size(); i++)
    {
        temp = WineryVector.operator [](i);
        ui->listWidget->addItem(temp.getName()); //temp.name;
    }
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
