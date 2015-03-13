#ifndef FULLTOUR_H
#define FULLTOUR_H

#include <QWidget>
<<<<<<< HEAD
=======
#include "intour.h"
#include <vector>
#include "Winery.h"
>>>>>>> a5d31d628648c32e2ec5fbecc714c02f71520129

namespace Ui {
class FullTour;
}

class FullTour : public QWidget
{
    Q_OBJECT

public:
    explicit FullTour(QWidget *parent = 0);
<<<<<<< HEAD
    ~FullTour();

private:
    Ui::FullTour *ui;
=======
    explicit FullTour(QWidget *parent, vector<Winery> WineryVector);
    ~FullTour();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FullTour *ui;
    inTour* tourWindow;
>>>>>>> a5d31d628648c32e2ec5fbecc714c02f71520129
};

#endif // FULLTOUR_H
