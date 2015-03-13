#include "newwine.h"
#include "ui_newwine.h"

newWine::newWine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newWine)
{
    ui->setupUi(this);
}

newWine::newWine(QWidget *parent, vector<Winery> WineryVector, int index) :
    QWidget(parent),
    ui(new Ui::newWine)
{
    ui->setupUi(this);
    WineryList = WineryVector;
    wineryIndex = index;
}

newWine::~newWine()
{
    delete ui;
}

void newWine::on_add_clicked()
{
    if(ui->name->text() != "" && ui->year->text().toInt() > 0 && ui->price->text().toFloat() > 0.0)
    {
        Wine newWine;
        newWine.SetName(ui->name->text());
        newWine.SetYear(ui->year->text().toInt());
        newWine.SetPrice(ui->price->text().toFloat());

        Winery* tempWinery = &(WineryList.operator [](wineryIndex));
        tempWinery->addWine(newWine);
        tempWinery->setNumOfWines(tempWinery->getNumOfWines() + 1);

        WriteFile("wineries.txt", WineryList);
        emit changeSuccess();
        this->close();
    }
}
