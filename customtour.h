#ifndef CUSTOMTOUR_H
#define CUSTOMTOUR_H

#include <QWidget>
#include "intour.h"

namespace Ui {
class CustomTour;
}

class CustomTour : public QWidget
{
    Q_OBJECT

public:
    explicit CustomTour(QWidget *parent = 0);
    ~CustomTour();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CustomTour *ui;
    inTour* tourWindow;
};

#endif // CUSTOMTOUR_H
