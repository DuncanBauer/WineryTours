#include "Winery.h"
#include <QDebug>
#include <QString>

Winery::Winery()
{
    name          = "";
    wineryNum     = 0;
    NumOfWines    = 0;
    distanceToMom = 0.0;
    visitable     = true;
}

Winery::Winery(QString        newName,
               int            newWineryNum,
               vector<float>  newNeighbors,
               WineList<Wine> newWines,
               int            newNumWines,
               float          newDistToMom,
               bool           isVisitable)
{
    name          = newName;
    wineryNum     = newWineryNum;
    neighbors     = newNeighbors;
    winesOffered  = newWines;
    NumOfWines    = newNumWines;
    distanceToMom = newDistToMom;
    visitable     = isVisitable;
}

Winery::~Winery()
{
}

void Winery::setName(QString newName)
{
    name = newName;
}

void Winery::setWineryNum(int num)
{
    wineryNum = num;
}

void Winery::setNumOfWines(int num)
{
    NumOfWines = num;
}

void Winery::setWineList(WineList<Wine> w)
{
    winesOffered.operator =(w);
    winesOffered.Print();
}

void Winery::setNeighbors(vector<float> newNeighbors)
{
    neighbors = newNeighbors;
}

void Winery::setDistanceToMom(float distance)
{
    distanceToMom = distance;
}

void Winery::setVisitable(bool isVisitable)
{
    visitable = isVisitable;
}
