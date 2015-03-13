#ifndef ADMINPORTAL_H
#define ADMINPORTAL_H

#include <QWidget>
#include <vector>
#include "Winery.h"
#include "newwine.h"

vector<Winery> ReadFile(QString fileName);

namespace Ui {
class AdminPortal;
}

class AdminPortal : public QWidget
{
    Q_OBJECT

public:
    explicit AdminPortal(QWidget *parent = 0);
    explicit AdminPortal(QWidget *parent, vector<Winery> newVector);
    ~AdminPortal();

private slots:
    void on_addWine_clicked();
    void RereadList();

private:
    void SetListItems();

    Ui::AdminPortal *ui;
    vector<Winery> WineryVector;
};

#endif // ADMINPORTAL_H
