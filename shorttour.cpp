#include "shorttour.h"
#include "mainwindow.h"

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
    this->setWindowTitle("RapeGrape Winery Tours");

    UserWineryList = WineryVector;

    ui->customTable->setShowGrid(true);
    ui->customTable->setColumnCount(2);
    ui->customTable->setRowCount(0);
    ui->customTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    int row = 0;
    unsigned int index = 0;

    for(index = 0; index < UserWineryList.size(); index++)
    {
        if(ui->customTable->rowCount() < row + 1)
        {
            ui->customTable->setRowCount(row + 1);
        }

        Winery item = UserWineryList.operator [](index);

        QStringList itemList;
        QString itemDistance = QString::number(item.getDistanceToMom()) + " miles";
        itemList << item.getName() << itemDistance;

        for(int column = 0; column < 2; column++)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem(itemList.at(column));
            ui->customTable->setItem(row, column, newItem);
        }
        row++;
    }
    row = 0;

    QStringList headers;
    headers << "Winery Name" << "Distance to Mom";
    ui->customTable->setHorizontalHeaderLabels(headers);
}

shortTour::~shortTour()
{
    delete ui;
}

void shortTour::on_pushButton_clicked()
{
    unsigned int numOfWineries = ui->spinBox->text().toInt();
    if(ui->customTable->currentItem() != NULL && (numOfWineries <= UserWineryList.size() && numOfWineries != 0))
    {
        int wineryNum;
        int itemIndex = ui->customTable->currentRow();

        Winery tempWinery = UserWineryList.operator [](itemIndex);
        vector<Winery> temp;
        temp.push_back(tempWinery);

        for(unsigned int index = 0; index < numOfWineries - 1; index++)
        {
            wineryNum = tempWinery.getClosestNeighbor(UserWineryList);
            temp.push_back(UserWineryList.operator [](wineryNum));
            tempWinery = UserWineryList.operator [](wineryNum);
            tempWinery.setVisitable(false);
        }

        tourWindow = new inTour(NULL, temp);
        tourWindow->show();
        this->close();
    }
    else if(ui->spinBox->text().toInt() > UserWineryList.size())
    {
        responseWindow* w = new responseWindow(NULL, "Error", "We do not have that many wineries affiliated with us");
        w->show();
    }
    else if(ui->spinBox->text().toInt() == 0)
    {
        responseWindow* w = new responseWindow(NULL, "Error", "You don't want to visit any wineries?");
        w->show();
    }
    else
    {
        responseWindow* w = new responseWindow(NULL, "Error", "Must select a winery to begin your tour from");
        w->show();
    }
}

void shortTour::on_back_clicked()
{
    MainWindow* w = new MainWindow();
    w->show();
    this->close();
}
