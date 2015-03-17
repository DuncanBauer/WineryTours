#ifndef END_H
#define END_H

#include <QWidget>
#include "Winery.h"

namespace Ui {
class end;
}

class end : public QWidget
{
    Q_OBJECT

public:
    explicit end(QWidget *parent = 0);
    explicit end(QWidget *parent, vector<Winery> theVector, WineList<Wine>* theWineList, float totalDist, float totalMoneySpent);
    ~end();

private slots:
    void on_close_clicked();

    void on_goAgain_clicked();

private:
    Ui::end *ui;
    vector<Winery> WineryVector;
    WineList<Wine>* WinesBought;
    float distTraveled;
    float moneySpent;
};

#endif // END_H
