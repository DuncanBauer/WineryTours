#ifndef WINERY_H
#define WINERY_H

using namespace std;
#include <qstring.h>
#include "List.h"
#include <vector>

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
    Winery(QString        newName,
           int            newWineryNum,
           vector<float>  newNeighbors,
           WineList<Wine> newWines,
           int            newNumWines,
           float          newDistToMom,
           bool           isVisitable);
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
    void setVisitable(bool isVisatable);

    // Getters
    QString        getName();
    int            getWineryNum();
    WineList<Wine> getWineList();
    int            getNumOfWines();
    int            getClosestNeighbor();
    float          getDistanceToMom();
    bool           getVisitable();
    QString toString();
};

#endif // WINERY_H
