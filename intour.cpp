#include "intour.h"
#include "ui_intour.h"
#include "mainwindow.h"
#include "end.h"

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
    this->setWindowTitle("RapeGrape Winery Tours");

    WineryList = WineryVector;
    currentWineryIndex = 0;
    currentWinery = WineryVector.operator [](currentWineryIndex);

    distTraveled   = currentWinery.getDistanceToMom();
    moneySpentHere = 0;
    totalSpent     = 0;

    winesPurchased = new WineList<Wine>();
    winesPurchased->SetCart(true);

    ui->winaryName->setText(currentWinery.getName());
    ui->winaryName->setAlignment(Qt::AlignCenter);

    ui->distanceTraveled->setText(QString::number(distTraveled) + " miles");
    ui->distanceTraveled->setAlignment(Qt::AlignCenter);

    ui->spentHere->setText(QString::number(moneySpentHere) + " dollars");
    ui->spentHere->setAlignment(Qt::AlignCenter);

    ui->totalSpent->setText(QString::number(totalSpent) + " dollars");
    ui->totalSpent->setAlignment(Qt::AlignCenter);

    ui->winesAvail->setShowGrid(true);
    ui->winesAvail->setColumnCount(3);
    ui->winesAvail->setRowCount(0);
    ui->winesAvail->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->SetAvailWines();

    ui->winesPurched->setShowGrid(true);
    ui->winesPurched->setColumnCount(3);
    ui->winesPurched->setRowCount(0);
    ui->winesPurched->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->SetWinesPurched();

    if(currentWineryIndex == WineryList.size() - 1)
    {
        responseWindow* w = new responseWindow(NULL, "Enjoy", "This is the last stop on your tour");
        w->show();
    }
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
        if(currentWineryIndex == WineryList.size() - 1)
        {
            responseWindow* w = new responseWindow(NULL, "Enjoy", "This is the last stop on your tour");
            w->show();
        }
        currentWinery = WineryList.operator [](currentWineryIndex);

        // I don't know why this works, but it does, so don't touch it
        distTraveled += WineryList.operator [](currentWineryIndex - 1).getNeighbors()->operator [](currentWinery.getWineryNum() - 1);
        moneySpentHere = 0;

        ui->winaryName->setText(currentWinery.getName());
        ui->winaryName->setAlignment(Qt::AlignCenter);

        ui->distanceTraveled->setText(QString::number(distTraveled) + " miles");
        ui->distanceTraveled->setAlignment(Qt::AlignCenter);

        ui->spentHere->setText(QString::number(moneySpentHere) + " dollars");
        ui->spentHere->setAlignment(Qt::AlignCenter);

        ui->totalSpent->setText(QString::number(totalSpent) + " dollars");
        ui->totalSpent->setAlignment(Qt::AlignCenter);

        SetAvailWines();
    }
    else
    {
        end* w = new end(NULL, WineryList, winesPurchased, distTraveled, totalSpent);
        w->show();
        this->close();
    }
}

void inTour::ClearAvailWines()
{
    ui->winesAvail->clear();
    for(int count = WineryList.size(); count > 0; count--)
    {
        ui->winesAvail->removeRow(count);
    }
}

void inTour::ClearWinesPurched()
{
    ui->winesPurched->clear();
    for(int count = WineryList.size(); count > 0; count--)
    {
        ui->winesPurched->removeRow(count);
    }
}

void inTour::SetAvailWines()
{
    this->ClearAvailWines();

    if(!WineryList.empty())
    {
        int row = 0;
        Winery tempWinery        = WineryList.operator [](currentWineryIndex);
        WineList<Wine>* tempList = tempWinery.getWineList();

        for(int index = 0; index < tempList->Size(); index++)
        {
            if(ui->winesAvail->rowCount() < row + 1)
            {
                ui->winesAvail->setRowCount(row + 1);
            }

            Wine* item = tempList->operator [](index);

            QStringList itemList;
            QString itemPrice = QString::number(item->GetPrice());
            QString itemYear  = QString::number(item->GetYear());
            itemList << item->GetName() << itemYear << itemPrice;

            for(int column = 0; column < 3; column++)
            {
                QTableWidgetItem *newItem = new QTableWidgetItem(itemList.at(column));
                ui->winesAvail->setItem(row, column, newItem);
            }
            row++;
        }
        row = 0;
    }

    QStringList headers;
    headers << "Name" << "Year" << "Price";

    ui->winesAvail->setHorizontalHeaderLabels(headers);
}

void inTour::SetWinesPurched()
{
    this->ClearWinesPurched();

     if(!winesPurchased->IsEmpty())
     {
         int row = 0;
         WineList<Wine>* tempList = winesPurchased;
         for(int index = 0; index < tempList->Size(); index++)
         {
             if(ui->winesPurched->rowCount() < row + 1)
             {
                 ui->winesPurched->setRowCount(row + 1);
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
                 ui->winesPurched->setItem(row, column, newItem);
             }
             row++;
         }
         row = 0;
     }

     QStringList headers;
     headers << "Name" << "Year" << "Quantity";

     ui->winesPurched->setHorizontalHeaderLabels(headers);
}

void inTour::on_purchWineButton_clicked()
{
    if(ui->winesAvail->currentItem() != NULL && ui->spinBox->text().toInt() != 0)
    {
        int wineIndex = ui->winesAvail->currentRow();
        WineList<Wine>* tempList = currentWinery.getWineList();

        Wine* temp = tempList->operator [](wineIndex);
        Wine tempWine = *temp;

        for(int index = 0; index < ui->spinBox->text().toInt(); index++)
        {
            winesPurchased->Add(tempWine);
        }

        SetWinesPurched();

        moneySpentHere += tempWine.GetPrice() * ui->spinBox->text().toInt();
        totalSpent     += tempWine.GetPrice() * ui->spinBox->text().toInt();

        ui->spentHere->setText(QString::number(moneySpentHere) + " dollars");
        ui->spentHere->setAlignment(Qt::AlignCenter);

        ui->totalSpent->setText(QString::number(totalSpent) + " dollars");
        ui->totalSpent->setAlignment(Qt::AlignCenter);
    }
    else if(ui->winesAvail->currentItem() == NULL)
    {
        responseWindow* w = new responseWindow(NULL, "Error", "Must select a wine to purchase");
        w->show();
    }
    else if(ui->spinBox->text().toInt() == 0)
    {
        responseWindow* w = new responseWindow(NULL, "Error", "You tried to purchase 0 bottles of wine");
        w->show();
    }
}
