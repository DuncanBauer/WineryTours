#ifndef SHORTTOUR_H
#define SHORTTOUR_H

#include <QWidget>

namespace Ui {
class shortTour;
}

class shortTour : public QWidget
{
    Q_OBJECT

public:
    explicit shortTour(QWidget *parent = 0);
    ~shortTour();

private:
    Ui::shortTour *ui;
};

#endif // SHORTTOUR_H
