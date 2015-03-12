#ifndef CUSTOMTOUR_H
#define CUSTOMTOUR_H

#include <QWidget>

namespace Ui {
class CustomTour;
}

class CustomTour : public QWidget
{
    Q_OBJECT

public:
    explicit CustomTour(QWidget *parent = 0);
    ~CustomTour();

private:
    Ui::CustomTour *ui;
};

#endif // CUSTOMTOUR_H
