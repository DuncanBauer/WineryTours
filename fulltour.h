#ifndef FULLTOUR_H
#define FULLTOUR_H

#include <QWidget>
#include "intour.h"
#include <vector>
#include "Winery.h"

namespace Ui {
class FullTour;
}

class FullTour : public QWidget
{
    Q_OBJECT

public:
    explicit FullTour(QWidget *parent = 0);
    explicit FullTour(QWidget *parent, vector<Winery> WineryVector);
    ~FullTour();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FullTour *ui;
    inTour* tourWindow;
};

#endif // FULLTOUR_H
