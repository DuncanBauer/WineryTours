#include "customtour.h"
#include "ui_customtour.h"
#include "mainwindow.h"

CustomTour::CustomTour(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomTour)
{
    ui->setupUi(this);
    this->setWindowTitle("RapeGrape Winery Tours");
}

CustomTour::CustomTour(QWidget *parent, vector<Winery> WineryVector) :
    QWidget(parent),
    ui(new Ui::CustomTour)
{
    ui->setupUi(this);
    this->setWindowTitle("RapeGrape Winery Tours");

    WineryList = WineryVector;

    ui->wineTable->setShowGrid(true);
    ui->wineTable->setColumnCount(2);
    ui->wineTable->setRowCount(0);
    ui->wineTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->SetListItems();


    ui->userList->setShowGrid(true);
    ui->userList->setColumnCount(2);
    ui->userList->setRowCount(0);
    ui->userList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->SetUserListItems();
}

CustomTour::~CustomTour()
{
    delete ui;
}

void CustomTour::SetListItems()
{
    ui->wineTable->clear();

    int row = 0;
    unsigned int index = 0;
    for(index = 0; index < WineryList.size(); index++)
    {
        if(ui->wineTable->rowCount() < row + 1)
        {
            ui->wineTable->setRowCount(row + 1);
        }

        Winery item = WineryList.operator [](index);

        QStringList itemList;
        QString itemDistance = QString::number(item.getDistanceToMom()) + " miles";
        itemList << item.getName() << itemDistance;

        for(int column = 0; column < 2; column++)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem(itemList.at(column));
            ui->wineTable->setItem(row, column, newItem);
        }
        row++;
    }
    row = 0;

    QStringList headers;
    headers << "Winery Name" << "Distance to Mom";
    ui->wineTable->setHorizontalHeaderLabels(headers);
}

void CustomTour::SetUserListItems()
{
    ui->userList->clear();
    int row = 0;
    for(unsigned int i = 0; i < UserWineryList.size(); i++)
    {
        if(ui->userList->rowCount() < row + 1)
        {
            ui->userList->setRowCount(row + 1);
        }
       Winery temp = UserWineryList.operator [](i);

        QStringList itemList;
        QString itemDistance = QString::number(temp.getDistanceToMom());
        itemList << temp.getName() << itemDistance;

        for(int column = 0; column < 2; column++)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem(itemList.at(column));
            ui->userList->setItem(row, column, newItem);
        }
        row++;
    }

    QStringList headers;
    headers << "Winery Name" << "Distance to Mom";
    ui->userList->setHorizontalHeaderLabels(headers);
}

void CustomTour::on_pushButton_clicked()
{
    if(!UserWineryList.empty())
    {
        UserWineryList = SortVector(UserWineryList);
        tourWindow = new inTour(NULL, UserWineryList);
        tourWindow->show();
        this->close();
    }
    else
    {
        responseWindow* w = new responseWindow(NULL, "Error", "You have yet to plan your tour");
        w->show();
    }
}

void CustomTour::on_add_clicked()
{
    if(ui->wineTable->currentItem() != NULL)
    {
        QTableWidgetItem *item = ui->wineTable->currentItem();
        int itemIndex = ui->wineTable->currentRow();
        int column = ui->wineTable->currentColumn();
        UserWineryList.push_back(WineryList.operator[] (itemIndex));

        for(unsigned int index = itemIndex; index < WineryList.size() - 1; index++)
        {
            WineryList.operator[](index) = WineryList.operator[](index + 1);
        }
        WineryList.pop_back();
        ui->userList->setItem(itemIndex, column, item);
        ui->wineTable->removeRow(itemIndex);

        SetListItems();
        SetUserListItems();
    }
    else
    {
        responseWindow* w = new responseWindow(NULL, "Error", "Must select a winery to add to your tour");
        w->show();
    }
}

void CustomTour::on_remove_clicked()
{
    if(ui->userList->currentItem() != NULL)
    {
        QTableWidgetItem *item = ui->userList->currentItem();
        int itemIndex = ui->userList->currentRow();
          int column = ui->wineTable->currentColumn();
        WineryList.push_back(UserWineryList.operator[] (itemIndex));

        for(unsigned int index = itemIndex; index < UserWineryList.size() - 1; index++)
        {
            UserWineryList.operator[](index) = UserWineryList.operator[](index + 1);
        }
        UserWineryList.pop_back();
        ui->wineTable->setItem(itemIndex, column, item);
        ui->userList->removeRow(itemIndex);

        SetListItems();
        SetUserListItems();
    }
    else
    {
        responseWindow* w = new responseWindow(NULL, "Error", "Must select a winery to remove from your tour");
        w->show();
    }
}

void CustomTour::on_back_clicked()
{
    MainWindow* w = new MainWindow();
    w->show();
    this->close();
}
