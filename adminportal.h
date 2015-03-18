#ifndef ADMINPORTAL_H
#define ADMINPORTAL_H

#include <QWidget>
#include <vector>
#include "Winery.h"
#include "newwine.h"

vector<Winery> ReadFile(QString fileName);
void WriteFile(QString fileName, vector<Winery>* WineryVector);

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
    void on_editList_clicked();
    void RereadList();

    void on_pushButton_clicked();

    void on_addWinery_clicked();

private:
    void SetListItems();
    void SetPendingListItems();

    Ui::AdminPortal *ui;
    vector<Winery> WineryVector;
    vector<Winery> pendingWineries;
};

#endif // ADMINPORTAL_H
