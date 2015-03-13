#ifndef DELETEWINE_H
#define DELETEWINE_H

#include <QWidget>

namespace Ui {
class deleteWine;
}

class deleteWine : public QWidget
{
    Q_OBJECT

public:
    explicit deleteWine(QWidget *parent = 0);
    ~deleteWine();

private:
    Ui::deleteWine *ui;
};

#endif // DELETEWINE_H
