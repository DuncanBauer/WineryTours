#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <qdir.h>
#include <windows.h>
#include "Winery.h"


int FindClosest(vector<float> myV, int& wineryNum)
{
    unsigned int index = 0;
    float smallest     =  myV[index];

    for(index = 1; index < myV.size(); index++)
    {
        if(smallest > myV[index] && myV[index]!= 0.0)
        {
            smallest  = myV[index];
            wineryNum = index + 1;
        }
    }
    return smallest;
}

void ResetAll(vector<Winery> wineryVector)
{
    for(unsigned int index = 0; index < wineryVector.size(); index++)
    {
        wineryVector.operator [](index).setVisitable(true);
    }
}

vector<Winery> ReadFile(QString fileName)
{
    vector<Winery> tempWineryVector;

    QFile wineryFile(fileName);
    QTextStream wineryInput(&wineryFile);
    if(!wineryFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(0,"Critical Failure","Winery file has failed to load");
        qDebug() << QDir::currentPath();
    }
    else
    {
        QString tempString;
        int     tempInt;
        float   tempFloat;
        Wine*   tempWine           = new Wine();
        Winery* tempWinery         = new Winery();
        WineList<Wine>* tempList   = new WineList<Wine>();
        vector<float>*  tempVector = new vector<float>();

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
                tempVector->push_back(wineryInput.readLine().toFloat());
            }
            // Assigns the vector of neighbors to the wineries neighbors
            tempWinery->setNeighbors(*tempVector);

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
            tempWinery->setWineList(tempList);

            // Pushes the winery onto the tempVector
            tempWineryVector.push_back(*tempWinery);

            // Reads the blank line in the input file between wineries
            tempString = wineryInput.readLine();

            // Allocates new memory
            tempWinery = new Winery();
            tempList   = new WineList<Wine>();
            tempVector = new vector<float>();
        }

        // Deletes unused allocated memory
        delete tempWinery;
        delete tempList;
        delete tempVector;
        delete tempWine;

        // Closes input file
        wineryFile.close();
    }
    return tempWineryVector;
}

void WriteFile(QString fileName, vector<Winery>* WineryVector)
{
    QFile wineryFile(fileName);
    QTextStream wineryOutput(&wineryFile);
    if(!wineryFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        QMessageBox::information(0,"Critical Failure","Winery file has failed to load");
        qDebug() << QDir::currentPath();
    }
    else
    {
        Winery* currentWinery;
        for(unsigned int index = 0; index < WineryVector->size(); index++)
        {
            currentWinery = &WineryVector->operator [](index);
            wineryOutput << currentWinery->getName()      << endl
                         << currentWinery->getWineryNum() << endl
                         << WineryVector->size()          << endl;

            for(unsigned int jndex = 0; jndex < WineryVector->size(); jndex++)
            {
                wineryOutput << currentWinery->getNeighbors().operator [](jndex) << endl;
            }

            wineryOutput << currentWinery->getDistanceToMom() << endl
                         << currentWinery->getNumOfWines()    << endl;

            WineList<Wine>* tempList = currentWinery->getWineList();
            if(tempList->Size() != 0)
            {
                Wine* tempWine;
                int jndex = 0;
                while(jndex < currentWinery->getNumOfWines())
                {
                    tempWine = tempList->operator [](jndex);
                    wineryOutput << tempWine->GetName()  << endl
                                 << tempWine->GetYear()  << endl
                                 << tempWine->GetPrice() << endl;
                    jndex++;
                }
            }
            wineryOutput << endl;
        }
        wineryFile.close();
    }
}
