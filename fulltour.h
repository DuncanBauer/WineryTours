#ifndef FULLTOUR_H
#define FULLTOUR_H

#include <QWidget>

namespace Ui {
class FullTour;
}

class FullTour : public QWidget
{
    Q_OBJECT

public:
    explicit FullTour(QWidget *parent = 0);
    ~FullTour();

private:
    Ui::FullTour *ui;
};

#endif // FULLTOUR_H
