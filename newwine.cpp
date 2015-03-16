#include "newwine.h"
#include "ui_newwine.h"
#include <iomanip>

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

    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->SetTableItems();
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

        ui->name->clear();
        ui->year->clear();
        ui->price->clear();

        Winery* tempWinery = &(WineryList.operator [](wineryIndex));
        tempWinery->addWine(newWine);
        tempWinery->setNumOfWines(tempWinery->getNumOfWines() + 1);

        WriteFile("wineries.txt", &WineryList);
        emit changeSuccess();

        WineryList = ReadFile("wineries.txt");
        this->SetTableItems();
    }
}

void newWine::ClearTable()
{
    ui->tableWidget->clear();
    for(int count = WineryList.size(); count > 0; count--)
    {
        ui->tableWidget->removeRow(count);
    }
}

void newWine::SetTableItems()
{
    this->ClearTable();

    if(!WineryList.empty())
    {
        int row = 0;
        Winery tempWinery        = WineryList.operator [](wineryIndex);
        WineList<Wine>* tempList = tempWinery.getWineList();

        for(int index = 0; index < tempList->Size(); index++)
        {
            if(ui->tableWidget->rowCount() < row + 1)
            {
                ui->tableWidget->setRowCount(row + 1);
            }

            Wine* item = tempList->operator [](index);

            QStringList itemList;
            QString itemYear  = QString::number(item->GetYear());
            QString itemPrice = QString::number(item->GetPrice());
            itemList << item->GetName() << itemYear << itemPrice;

            for(int column = 0; column < 3; column++)
            {
                QTableWidgetItem *newItem = new QTableWidgetItem(itemList.at(column));
                ui->tableWidget->setItem(row, column, newItem);
            }
            row++;
        }
        row = 0;
    }

    QStringList headers;
    headers << "Name" << "Year" << "Price";

    ui->tableWidget->setHorizontalHeaderLabels(headers);
}

void newWine::on_close_clicked()
{
    this->close();
}

void newWine::on_delete_2_clicked()
{
    if(ui->tableWidget->currentItem() != NULL && !WineryList.empty())
    {
        Winery* tempWinery       = &WineryList.operator [](wineryIndex);
        WineList<Wine>* tempList = tempWinery->getWineList();

        int index = ui->tableWidget->currentRow();
        tempList->Delete(index);
        tempWinery->setNumOfWines(tempWinery->getNumOfWines() - 1);

        for(int jndex = 0; jndex < tempList->Size(); jndex++)
        {
            tempList->operator [](jndex)->Print();
        }

        for(int jndex = 0; jndex < WineryList.operator [](wineryIndex).getNumOfWines(); jndex++)
        {
            WineryList.operator [](wineryIndex).getWineList()->operator [](jndex)->Print();
        }

        WriteFile("wineries.txt", &WineryList);

        emit changeSuccess();
        WineryList = ReadFile("wineries.txt");
        this->SetTableItems();
    }
}

void newWine::on_edit_clicked()
{
    if(ui->tableWidget->currentItem() != NULL)
    {
        int index                = ui->tableWidget->currentRow();
        Winery* tempWinery       = &WineryList.operator [](wineryIndex);
        WineList<Wine>* tempList = tempWinery->getWineList();
        Wine* tempWine           = tempList->GetData(index);

        if(ui->name->text() != "")
        {
            tempWine->SetName(ui->name->text());
        }
        if(ui->year->text().toInt() > 0 && ui->year->text().toInt() <= 9999)
        {
            tempWine->SetYear(ui->year->text().toInt());
        }
        if(ui->price->text().toFloat() > 0 && ui->price->text().toFloat() <= 1000000)
        {
            tempWine->SetPrice(ui->price->text().toFloat());
        }

        ui->name->clear();
        ui->year->clear();
        ui->price->clear();

        WriteFile("wineries.txt", &WineryList);
        emit changeSuccess();
        WineryList = ReadFile("wineries.txt");
        this->SetTableItems();
    }
}
