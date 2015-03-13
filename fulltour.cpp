#include "fulltour.h"
#include "ui_fulltour.h"

FullTour::FullTour(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FullTour)
{
    ui->setupUi(this);
}

FullTour::FullTour(QWidget *parent, vector<Winery> WineryVector) :
    QWidget(parent),
    ui(new Ui::FullTour)
{
    ui->setupUi(this);
    tourWindow = new inTour();

    Winery temp;
    for(unsigned int i = 0; i < WineryVector.size(); i++)
    {
        temp = WineryVector.operator [](i);
        ui->listWidget->addItem(temp.getName()); //temp.name;
    }
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
