#ifndef NEWWINE_H
#define NEWWINE_H

#include <QWidget>
#include <vector>
#include "Winery.h"
#include "Wine.h"

void WriteFile(QString fileName, vector<Winery> *WineryVector);
vector<Winery> ReadFile(QString fileName);

namespace Ui {
class newWine;
}

class newWine : public QWidget
{
    Q_OBJECT

public:
    explicit newWine(QWidget *parent = 0);
    explicit newWine(QWidget *parent, vector<Winery> WineryVector, int index);
    ~newWine();

signals:
    void changeSuccess();

private slots:
    void on_add_clicked();
    void SetTableItems();
    void ClearTable();
    void on_close_clicked();
    void on_delete_2_clicked();

private:
    Ui::newWine *ui;
    vector<Winery> WineryList;
    int wineryIndex;
};

#endif // NEWWINE_H
