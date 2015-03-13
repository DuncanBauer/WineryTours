#ifndef SHORTTOUR_H
#define SHORTTOUR_H

#include <QWidget>
#include "intour.h"
#include <vector>
#include "Winery.h"

namespace Ui {
class shortTour;
}

class shortTour : public QWidget
{
    Q_OBJECT

public:
    explicit shortTour(QWidget *parent = 0);
    explicit shortTour(QWidget *parent, vector<Winery> WineryVector);
    ~shortTour();

private slots:
    void on_pushButton_clicked();

private:
    Ui::shortTour *ui;
    vector<Winery> UserWineryList;
    inTour* tourWindow;
};

#endif // SHORTTOUR_H
