#include "customtour.h"
#include "ui_customtour.h"

CustomTour::CustomTour(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomTour)
{
    ui->setupUi(this);
}

CustomTour::CustomTour(QWidget *parent, vector<Winery> WineryVector) :
    QWidget(parent),
    ui(new Ui::CustomTour)
{
    ui->setupUi(this);
    WineryList = WineryVector;
    SetListItems();
}

CustomTour::~CustomTour()
{
    delete ui;
}

void CustomTour::SetListItems()
{
    ui->listWidget->clear();
    Winery temp;
    for(unsigned int i = 0; i < WineryList.size(); i++)
    {
        temp = WineryList.operator [](i);
        ui->listWidget->addItem(temp.getName()); //temp.name;
    }
}

void CustomTour::SetUserListItems()
{
    ui->userList->clear();
    Winery temp;
    for(unsigned int i = 0; i < UserWineryList.size(); i++)
    {
        temp = UserWineryList.operator [](i);
        ui->userList->addItem(temp.getName()); //temp.name;
    }
}

void CustomTour::on_pushButton_clicked()
{
    tourWindow = new inTour(NULL, UserWineryList);
    tourWindow->show();
    this->close();
}

void CustomTour::on_add_clicked()
{
    if(ui->listWidget->currentItem() != NULL)
    {
        QListWidgetItem *item = ui->listWidget->currentItem();
        int itemIndex = ui->listWidget->currentRow();
        UserWineryList.push_back(WineryList.operator[] (itemIndex));

        for(unsigned int index = itemIndex; index < WineryList.size() - 1; index++)
        {
            WineryList.operator[](index) = WineryList.operator[](index + 1);
        }
        WineryList.pop_back();
        ui->userList->addItem(item);
        ui->listWidget->removeItemWidget(item);

        SetListItems();
        SetUserListItems();
    }
}

void CustomTour::on_remove_clicked()
{
    if(ui->userList->currentItem() != NULL)
    {
        QListWidgetItem *item = ui->userList->currentItem();
        int itemIndex = ui->userList->currentRow();
        WineryList.push_back(UserWineryList.operator[] (itemIndex));

        for(unsigned int index = itemIndex; index < UserWineryList.size() - 1; index++)
        {
            UserWineryList.operator[](index) = UserWineryList.operator[](index + 1);
        }
        UserWineryList.pop_back();
        ui->listWidget->addItem(item);
        ui->userList->removeItemWidget(item);

        SetListItems();
        SetUserListItems();
    }
}
