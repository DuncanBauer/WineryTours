#ifndef WINERY_H
#define WINERY_H

using namespace std;
#include <qstring.h>
#include <vector>

class Winery{
private:
    QString name;
    int     wineryNum;
    vector<float> neighbors;
    WineList    winesOffered;
    int     NumOfWines;
    float   distanceToMom;
    bool    visitable;
public:
    void setName(QString name);
    void setWineryNum(int num);
    void setWineList(WineList w);
    void setNumOfWines(int num);
    void setNeighbors(vector<float> neighbors);
    void setDistanceToMom(float distance);
    void setVisitable(bool visatable);
    QString getName();
    int     getWinesNum();
    WineList getWineList();
    int     getWinesOffered();
    int  getClosestNeighbor(vector<float> neighbors);
    float getDistanceToMom();
    bool getVisitable();
    QString toString();
};

void setName(QString name);
void setWineryNum(int num);
void setWineList(WineList w);
void setNumOfWines(int num);
void setNeighbors(vector<float> neighbors);
void setDistanceToMom(float distance);
void setVisitable(bool visatable);
QString getName();
int     getWinesNum();
WineList getWineList();
int     getWinesOffered();
int  getClosestNeighbor(vector<float> neighbors);
float getDistanceToMom();
bool getVisitable();
QString toString();

#endif // WINERY_H
