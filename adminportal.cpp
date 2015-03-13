#include "adminportal.h"
#include "ui_adminportal.h"

AdminPortal::AdminPortal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminPortal)
{
    ui->setupUi(this);
}

AdminPortal::AdminPortal(QWidget *parent, vector<Winery> newVector) :
    QWidget(parent),
    ui(new Ui::AdminPortal)
{
    ui->setupUi(this);
    WineryVector = newVector;
    SetListItems();
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

void AdminPortal::on_addWine_clicked()
{
    if(ui->wineries->currentItem() != NULL)
    {
        unsigned int index = ui->wineries->currentRow();
        qDebug() << index;
        newWine* w = new newWine(NULL, WineryVector, index);
        connect(w, SIGNAL(changeSuccess()), this, SLOT(RereadList()));
        w->show();
    }
}

void AdminPortal::RereadList()
{
    WineryVector = ReadFile("wineries.txt");
}
