#ifndef INTOUR_H
#define INTOUR_H

#include <QWidget>
#include <vector>
#include "Winery.h"

namespace Ui {
class inTour;
}

class inTour : public QWidget
{
    Q_OBJECT

public:
    explicit inTour(QWidget *parent = 0);
    explicit inTour(QWidget *parent, vector<Winery> WineryVector);
    ~inTour();

private slots:
    void on_nextButton_clicked();
    void on_purchWineButton_clicked();

private:
    void ClearAvailWines();
    void SetAvailWines();
    void SetWinesPurched();
    void ClearWinesPurched();

    Ui::inTour *ui;
    vector<Winery> WineryList;
    Winery currentWinery;
    unsigned int numOfWineries;
    unsigned int currentWineryIndex;

    WineList<Wine>* winesPurchased;
    float moneySpentHere;
    float totalSpent;
    float distTraveled;
};

#endif // INTOUR_H
