#include "shorttour.h"

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

    UserWineryList = WineryVector;

    ui->customTable->setShowGrid(true);
    ui->customTable->setColumnCount(2);
    ui->customTable->setRowCount(0);
    ui->customTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
   // this->SetListItems();

    int row = 0;
    unsigned int index = 0;
    //Winery tempWinery;       // = WineryList.operator [](index);
    //WineList<Wine>* tempList = tempWinery.getWineList();

    for(index = 0; index < UserWineryList.size(); index++)
    {
        if(ui->customTable->rowCount() < row + 1)
        {
            ui->customTable->setRowCount(row + 1);
        }

        Winery item = UserWineryList.operator [](index);

        QStringList itemList;
        QString itemDistance = QString::number(item.getDistanceToMom());
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
}
