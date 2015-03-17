#include "adminportal.h"
#include "ui_adminportal.h"
#include "mainwindow.h"

AdminPortal::AdminPortal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminPortal)
{
    ui->setupUi(this);
    this->setWindowTitle("Admin Portal");
    WineryVector = ReadFile("wineries.txt");
    pendingWineries = ReadFile("pending.txt");
    SetListItems();
    SetPendingListItems();
}

AdminPortal::AdminPortal(QWidget *parent, vector<Winery> newVector) :
    QWidget(parent),
    ui(new Ui::AdminPortal)
{
    ui->setupUi(this);
    WineryVector = newVector;
    pendingWineries = ReadFile("pending.txt");
    SetListItems();
    SetPendingListItems();
}

AdminPortal::~AdminPortal()
{
    delete ui;
}

void AdminPortal::SetListItems()
{
    ui->wineries->clear();
    Winery temp;
    for(unsigned int i = 0; i < WineryVector.size(); i++)
    {
        temp = WineryVector.operator [](i);
        ui->wineries->addItem(temp.getName());
    }
}

void AdminPortal::SetPendingListItems()
{
    ui->pendingWineries->clear();
    Winery temp;
    for(unsigned int i = 0; i < pendingWineries.size(); i++)
    {
        temp = pendingWineries.operator [](i);
        ui->pendingWineries->addItem(temp.getName());
    }
}

void AdminPortal::on_editList_clicked()
{
    if(ui->wineries->currentItem() != NULL)
    {
        unsigned int index = ui->wineries->currentRow();
        newWine* w = new newWine(NULL, WineryVector, index);
        connect(w, SIGNAL(changeSuccess()), this, SLOT(RereadList()));
        w->show();
    }
    else
    {
        responseWindow* w = new responseWindow(NULL, "Error", "Must select a winery to edit its wine list");
        w->show();
    }
}

void AdminPortal::RereadList()
{
    WineryVector = ReadFile("wineries.txt");
    SetListItems();
}

void AdminPortal::on_pushButton_clicked()
{
    MainWindow* w = new MainWindow();
    w->show();
    this->close();
}

void AdminPortal::on_addWinery_clicked()
{
    if(ui->pendingWineries->currentItem() != NULL && ui->pendingWineries->currentRow() == 0)
    {
        unsigned int index = ui->pendingWineries->currentRow();
        Winery       temp  = pendingWineries.operator [](index);

        while(index < pendingWineries.size() - 1)
        {
            pendingWineries.operator [](index) = pendingWineries.operator [](index + 1);
            index++;
        }
        pendingWineries.pop_back();

        WineryVector.push_back(temp);

        vector<float>* tempVector;
        for(unsigned int jndex = 0; jndex < WineryVector.size() - 1; jndex++)
        {
             tempVector = WineryVector.operator [](jndex).getNeighbors();
             tempVector->push_back(temp.getNeighbors()->operator [](jndex));
        }
        WriteFile("wineries.txt", &WineryVector);
        WriteFile("pending.txt", &pendingWineries);
        ReadFile("wineries.txt");
        ReadFile("pending.txt");
        SetListItems();
        SetPendingListItems();
    }
    else if(ui->pendingWineries->currentItem() == NULL)
    {
        responseWindow* w = new responseWindow(NULL, "Error", "Must select a winery to add to the list of wineries");
        w->show();
    }
    else if(ui->pendingWineries->currentRow() != 0)
    {
        responseWindow* w = new responseWindow(NULL, "Error", "Please select the first winery in the pending winery list");
        w->show();
    }
}
