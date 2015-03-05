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
    void addNeighbor(float disToNeighbor);

    // Getters
    QString        getName();
    int            getWineryNum();
    WineList<Wine> getWineList();
    int            getNumOfWines();
    int            getClosestNeighbor();
    float          getDistanceToMom();
    bool           getVisitable();

    // Output Methods
    void toString();
};

#endif // WINERY_H
