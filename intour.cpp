#include "intour.h"
#include "ui_intour.h"
#include "mainwindow.h"
#include "VectorWrapper.h"

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

    winesPurchased = new WineList<Wine>();
    winesPurchased->SetCart(true);

    ui->winaryName->setText(currentWinery->getName());
    ui->winaryName->setAlignment(Qt::AlignCenter);

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
        ui->winaryName->setAlignment(Qt::AlignCenter);
        SetAvailWines();
    }
    else
    {
        MainWindow* w = new MainWindow();
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

             Wine* item = tempList->operator [](index);
             node<Wine>* tempNode = tempList->GetHead();

             for(int jndex = 0; jndex < index; jndex++)
             {
                 tempNode = tempNode->next;
             }

             QStringList itemList;
             QString     itemYear     = QString::number(item->GetYear());
             QString     itemQuantity = QString::number(tempNode->quantity);
             itemList << item->GetName() << itemYear << itemQuantity;

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
    if(ui->winesAvail->currentItem() != NULL)
    {
//        int wineIndex = ui->winesAvail->currentRow();
//        qDebug() << wineIndex;
        WineList<Wine>* tempList = currentWinery->getWineList();
        Wine* tempWine = tempList->operator [](ui->winesAvail->currentRow());

        for(int index = 0; index < ui->spinBox->text().toInt(); index++)
        {
            winesPurchased->Add(*tempWine);
        }
        SetWinesPurched();
    }
}
