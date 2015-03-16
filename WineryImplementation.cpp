#include "Winery.h"

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

void Winery::addWine(Wine newWine)
{
    winesOffered.Add(newWine);
}

QString Winery::getName()
{
    return name;
}

int Winery::getWineryNum()
{
    return wineryNum;
}

Wine* Winery::getWine(int index)
{
    return winesOffered.operator [](index);
}

WineList<Wine>* Winery::getWineList()
{
    return &winesOffered;
}

int Winery::getNumOfWines()
{
    return NumOfWines;
}

vector<float> Winery::getNeighbors()
{
    return neighbors;
}

int Winery::getClosestNeighbor(vector<Winery> WineryVector)
{
    unsigned int index = 0;
    int wineryIndex    = 0;
    float smallest     = neighbors.operator [](index);
    Winery temp;

    for(index = 1; index < neighbors.size(); index++)
    {
        temp = WineryVector.operator [](index);
        if(temp.getVisitable() && (smallest > neighbors.operator [](index) && neighbors.operator [](index) != 0.0))
        {
            smallest  = neighbors.operator [](index);
            wineryIndex = index + 1;
        }
    }
    return wineryIndex;
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

    qDebug() << endl;
}
