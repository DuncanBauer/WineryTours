#ifndef WINERY_H
#define WINERY_H

#include <qdebug.h>
#include <QString>
#include <vector>
#include "List.h"
#include "Wine.h"

using namespace std;

class Winery
{
private:
    QString        name;
    int            wineryNum;
    vector<float>  neighbors;
    WineList<Wine> winesOffered;
    int            NumOfWines;
    float          distanceToMom;
    bool           visitable;

public:
    Winery();
    ~Winery();

    // Overloaded Operators
    Winery& operator =(const Winery& ojb);

    // Setters
    void setName(QString newName);
    void setWineryNum(int num);
    void setWineList(WineList<Wine>* w);
    void setNumOfWines(int num);
    void setNeighbors(vector<float> newNeighbors);
    void setDistanceToMom(float distance);
    void setVisitable(bool isVisitable);
    void addNeighbor(float disToNeighbor);
    void addWine(Wine newWine);

    // Getters
    QString        getName();
    int            getWineryNum();
    WineList<Wine>* getWineList();
    Wine*          getWine(int index);
    int            getNumOfWines();
    vector<float>*  getNeighbors();
    int            getClosestNeighbor(vector<Winery> WineryVector);
    float          getDistanceToMom();
    bool           getVisitable();

    // Output Methods
    void toString();
};

#endif // WINERY_H
