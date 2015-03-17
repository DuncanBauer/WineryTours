#ifndef FULLTOUR_H
#define FULLTOUR_H

#include <QWidget>
#include "Winery.h"

vector<Winery> SortVector(vector<Winery> WineryVector);

namespace Ui {
class fullTour;
}

class fullTour : public QWidget
{
    Q_OBJECT

public:
    explicit fullTour(QWidget *parent = 0);
    explicit fullTour(QWidget *parent, vector<Winery> tempWineryVector);
    ~fullTour();

private slots:
    void on_back_clicked();

    void on_pushButton_clicked();

private:
    void SetListItems();
    Ui::fullTour *ui;
    vector<Winery> WineryVector;
};

#endif // FULLTOUR_H
