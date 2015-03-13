#include "fulltour.h"
#include "ui_fulltour.h"

FullTour::FullTour(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FullTour)
{
    ui->setupUi(this);
}

<<<<<<< HEAD
=======
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

>>>>>>> a5d31d628648c32e2ec5fbecc714c02f71520129
FullTour::~FullTour()
{
    delete ui;
}
<<<<<<< HEAD
=======

void FullTour::on_pushButton_clicked()
{
    tourWindow->show();
    this->close();
}
>>>>>>> a5d31d628648c32e2ec5fbecc714c02f71520129
