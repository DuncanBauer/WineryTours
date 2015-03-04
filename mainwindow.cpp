#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "List.h"
#include "Winery.h"
#include <QDebug>
#include <windows.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile wineryFile("wineries.txt");
    QTextStream wineryInput(&wineryFile);
    if(!wineryFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"Critical Failure","Winery file has failed to load");
    }

    vector<Winery> WineryVector;

    QString tempString;
    int     tempInt;
    float   tempFloat;
    vector<float> tempVector;
    WineList<Wine>* tempList = new WineList<Wine>();
    Winery* tempWinery       = new Winery();
    Wine*   tempWine         = new Wine();

    // Loops until the end of the file is reached
    while(!wineryInput.atEnd())
    {
        // Extracts and assigns winery name
        tempString = wineryInput.readLine();
        tempWinery->setName(tempString);

        // Extracts and assigns winery number
        tempInt = wineryInput.readLine().toInt();
        tempWinery->setWineryNum(tempInt);

        // Extracts number of neighbor wineries and loops
        // for the amount of wineries
        tempInt = wineryInput.readLine().toInt();
        for(int index = 0; index < tempInt; index++)
        {
            // Extracts and stores the distance to a certain
            // winery
            tempVector.push_back(wineryInput.readLine().toFloat());
        }
        // Assigns the vector of neighbors to the wineries neighbors
        tempWinery->setNeighbors(tempVector);

        // Extracts and assigns the distance to the Canyon Villa
        tempFloat = wineryInput.readLine().toFloat();
        tempWinery->setDistanceToMom(tempFloat);

        // Extracts and assigns the amount of wines the winery
        // carries and loops for the amount of wines
        tempInt = wineryInput.readLine().toInt();
        tempWinery->setNumOfWines(tempInt);
        for(int jndex = 0; jndex < tempInt; jndex++)
        {
            // Extracts / assigns / pushes the name, year, and price
            // of each wine to a wine list
            tempWine->SetName(wineryInput.readLine());
            tempWine->SetYear(wineryInput.readLine().toInt());
            tempWine->SetPrice(wineryInput.readLine().toFloat());
            tempList->Add(*tempWine);
            tempWine = new Wine();
        }
        // Assigns the list of wines to the wineries wine list
        tempWinery->setWineList(*tempList);
        // Pushes the winery onto the wineryVector
        WineryVector.push_back(*tempWinery);

        // Reads the blank line in the input file between wineries
        tempString = wineryInput.readLine();

        // Allocates new memory
        tempWinery = new Winery();
        tempList   = new WineList<Wine>();
    }
    // Deletes unused allocated memory
    delete tempWinery;
    delete tempList;
    delete tempWine;
    // Closes input file
    wineryFile.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
