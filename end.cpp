#include "end.h"
#include "ui_end.h"
#include "mainwindow.h"

end::end(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::end)
{
    ui->setupUi(this);
}

end::end(QWidget *parent, vector<Winery> theVector, WineList<Wine>* theWineList, float totalDist, float totalMoneySpent) :
    QWidget(parent),
    ui(new Ui::end)
{
    ui->setupUi(this);
    this->setWindowTitle("Tour Summary");

    WineryVector = theVector;
    WinesBought  = theWineList;
    distTraveled = totalDist;
    moneySpent   = totalMoneySpent;

    ui->distTraveled->setText(QString::number(distTraveled) + " miles");
    ui->distTraveled->setAlignment(Qt::AlignCenter);

    ui->totalSpent->setText(QString::number(moneySpent) + " dollars");
    ui->totalSpent->setAlignment(Qt::AlignCenter);

    ui->wineryList->setShowGrid(true);
    ui->wineryList->setColumnCount(2);
    ui->wineryList->setRowCount(0);
    ui->wineryList->setEditTriggers(QAbstractItemView::NoEditTriggers);

    int row = 0;
    unsigned int index = 0;
    for(index = 0; index < WineryVector.size(); index++)
    {
        if(ui->wineryList->rowCount() < row + 1)
        {
            ui->wineryList->setRowCount(row + 1);
        }

        Winery item = WineryVector.operator [](index);

        QStringList itemList;
        QString itemDistance = QString::number(item.getDistanceToMom()) + " miles";
        itemList << item.getName() << itemDistance;

        for(int column = 0; column < 2; column++)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem(itemList.at(column));
            ui->wineryList->setItem(row, column, newItem);
        }
        row++;
    }
    row = 0;

    QStringList headers;
    headers << "Winery Name" << "Distance to Mom";
    ui->wineryList->setHorizontalHeaderLabels(headers);


    ui->wineList->setShowGrid(true);
    ui->wineList->setColumnCount(3);
    ui->wineList->setRowCount(0);
    ui->wineList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    if(!WinesBought->IsEmpty())
    {
        int row = 0;
        WineList<Wine>* tempList = WinesBought;
        for(int index = 0; index < tempList->Size(); index++)
        {
            if(ui->wineList->rowCount() < row + 1)
            {
                ui->wineList->setRowCount(row + 1);
            }

            Wine* item2 = tempList->operator [](index);
            Wine item = *item2;
            node<Wine>* tempNode = tempList->GetHead();

            for(int jndex = 0; jndex < index; jndex++)
            {
                tempNode = tempNode->next;
            }

            QStringList itemList;
            QString     itemYear     = QString::number(item.GetYear());
            QString     itemQuantity = QString::number(tempNode->quantity);
            itemList << item.GetName() << itemYear << itemQuantity;

            for(int column = 0; column < 3; column++)
            {
                QTableWidgetItem *newItem = new QTableWidgetItem(itemList.at(column));
                ui->wineList->setItem(row, column, newItem);
            }
            row++;
        }
        row = 0;
    }

    QStringList headers2;
    headers2 << "Name" << "Year" << "Quantity";

    ui->wineList->setHorizontalHeaderLabels(headers2);
}

end::~end()
{
    delete ui;
}

void end::on_close_clicked()
{
    this->close();
}

void end::on_goAgain_clicked()
{
    MainWindow* w = new MainWindow();
    w->show();
    this->close();
}
