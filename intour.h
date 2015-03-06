#ifndef INTOUR_H
#define INTOUR_H

#include <QWidget>

namespace Ui {
class inTour;
}

class inTour : public QWidget
{
    Q_OBJECT

public:
    explicit inTour(QWidget *parent = 0);
    ~inTour();

private:
    Ui::inTour *ui;
};

#endif // INTOUR_H
