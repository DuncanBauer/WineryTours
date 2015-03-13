#ifndef INTOUR_H
#define INTOUR_H

#include <QWidget>
#include <vector>
#include <Winery.h>

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

private:
    Ui::inTour *ui;
    vector<Winery> WineryList;
};

#endif // INTOUR_H
