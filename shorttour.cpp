#include "shorttour.h"
#include "ui_shorttour.h"

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

    Winery temp;
    for(unsigned int i = 0; i < WineryVector.size(); i++)
    {
        temp = WineryVector.operator [](i);
        ui->listWidget->addItem(temp.getName()); //temp.name;
    }
}

shortTour::~shortTour()
{
    delete ui;
}

void shortTour::on_pushButton_clicked()
{
    if(ui->listWidget->currentItem() != NULL)
    {
        int wineryNum;
        int itemIndex; = ui->listWidget->currentRow();
        int numOfWineries = ui->spinBox->text().toInt();
        Winery tempWinery = UserWineryList.operator [](itemIndex);

        vector<Winery> temp;
        temp.push_back(tempWinery);

        for(int index = 0; index < numOfWineries - 2; index++)
        {
            wineryNum = tempWinery.getClosestNeighbor();
            temp.pop_back(UserWineryList.operator [](wineryNum));
            tempWinery = UserWineryList.operator [](wineryNum);
            tempWinery.setVisitable(false);
        }

        tourWindow = new inTour(NULL, UserWineryList);
        tourWindow->show();
        this->close();
    }
}
