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

Winery::~Winery()
{
}

Winery& Winery::operator =(const Winery& obj)
{
    this->name          = obj.name;
    this->wineryNum     = obj.wineryNum;
    this->neighbors     = obj.neighbors;
    this->winesOffered  = obj.winesOffered;
    this->NumOfWines    = obj.NumOfWines;
    this->distanceToMom = obj.distanceToMom;
    this->visitable     = obj.visitable;
    return *this;
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

void Winery::setWineList(WineList<Wine>* w)
{
    this->winesOffered.operator =(*w);
    delete w;
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

void Winery::addNeighbor(float disToNeighbor)
{
    neighbors.push_back(disToNeighbor);
}

QString Winery::getName()
{
    return name;
}

int Winery::getWineryNum()
{
    return wineryNum;
}

WineList<Wine> Winery::getWineList()
{
    return winesOffered;
}

int Winery::getNumOfWines()
{
    return NumOfWines;
}

int Winery::getClosestNeighbor()
{
    int   closest     = this->wineryNum;
    float closestDist = 0.0;

    for(int index = 0; index < neighbors.size(); index++)
    {
        if(neighbors[index] < closestDist)
        {
            closestDist = neighbors[index];
            closest = index;
        }
    }
    return closest;
}

float Winery::getDistanceToMom()
{
    return distanceToMom;
}

bool Winery::getVisitable()
{
    return visitable;
}

void Winery::toString()
{
    qDebug() << this->getName() << endl
             << "Winery: " << this->getWineryNum() << endl
             << "Miles from Canyon Villa: " << this->getDistanceToMom() << endl
             << "Number of wines available: " << this->getNumOfWines() << endl
             << "Wines: ";

    this->getWineList().Print();\

    qDebug() << endl;
}
