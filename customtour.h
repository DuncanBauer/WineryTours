#ifndef CUSTOMTOUR_H
#define CUSTOMTOUR_H

#include <QWidget>
#include <vector>
#include "Winery.h"
#include "intour.h"

namespace Ui {
class CustomTour;
}

vector<Winery> SortVector(vector<Winery> WineryVector);

class CustomTour : public QWidget
{
    Q_OBJECT

public:
    explicit CustomTour(QWidget *parent = 0);
    explicit CustomTour(QWidget *parent, vector<Winery> WineryVector);
    ~CustomTour();


private slots:
    void on_pushButton_clicked();

    void on_add_clicked();

    void on_remove_clicked();

    void on_back_clicked();

private:
    void SetListItems();
    void SetUserListItems();
    Ui::CustomTour *ui;
    inTour* tourWindow;
    vector<Winery> WineryList;
    vector<Winery> UserWineryList;
};

#endif // CUSTOMTOUR_H
