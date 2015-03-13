#ifndef CUSTOMTOUR_H
#define CUSTOMTOUR_H

#include <QWidget>
<<<<<<< HEAD
=======
#include <vector>
#include <Winery.h>
#include "intour.h"
>>>>>>> a5d31d628648c32e2ec5fbecc714c02f71520129

namespace Ui {
class CustomTour;
}

class CustomTour : public QWidget
{
    Q_OBJECT

public:
    explicit CustomTour(QWidget *parent = 0);
<<<<<<< HEAD
    ~CustomTour();

private:
    Ui::CustomTour *ui;
=======
    explicit CustomTour(QWidget *parent, vector<Winery> WineryVector);
    ~CustomTour();

private slots:
    void on_pushButton_clicked();

    void on_add_clicked();

    void on_remove_clicked();

private:
    void SetListItems();
    void SetUserListItems();
    Ui::CustomTour *ui;
    inTour* tourWindow;
    vector<Winery> WineryList;
    vector<Winery> UserWineryList;
>>>>>>> a5d31d628648c32e2ec5fbecc714c02f71520129
};

#endif // CUSTOMTOUR_H
