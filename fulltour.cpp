#include "fulltour.h"
#include "ui_fulltour.h"
#include "mainwindow.h"

fullTour::fullTour(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fullTour)
{
    ui->setupUi(this);
}

fullTour::fullTour(QWidget *parent, vector<Winery> tempWineryVector) :
    QWidget(parent),
    ui(new Ui::fullTour)
{
    ui->setupUi(this);
    this->setWindowTitle("RapeGrape Winery Tours");
    WineryVector = SortVector(tempWineryVector);

    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->SetListItems();
}

fullTour::~fullTour()
{
    delete ui;
}

void fullTour::SetListItems()
{
    ui->tableWidget->clear();

    int row = 0;
    unsigned int index = 0;
    for(index = 0; index < WineryVector.size(); index++)
    {
        if(ui->tableWidget->rowCount() < row + 1)
        {
            ui->tableWidget->setRowCount(row + 1);
        }

        Winery item = WineryVector.operator [](index);

        QStringList itemList;
        QString itemDistance = QString::number(item.getDistanceToMom()) + " miles";
        itemList << item.getName() << itemDistance;

        for(int column = 0; column < 2; column++)
        {
            QTableWidgetItem *newItem = new QTableWidgetItem(itemList.at(column));
            ui->tableWidget->setItem(row, column, newItem);
        }
        row++;
    }
    row = 0;

    QStringList headers;
    headers << "Winery Name" << "Distance to Mom";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
}

void fullTour::on_back_clicked()
{
    MainWindow* w = new MainWindow();
    w->show();
    this->close();
}

void fullTour::on_pushButton_clicked()
{
    inTour* w = new inTour(NULL, WineryVector);
    w->show();
    this->close();
}
