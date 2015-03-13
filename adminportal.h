#ifndef ADMINPORTAL_H
#define ADMINPORTAL_H

#include <QWidget>

namespace Ui {
class AdminPortal;
}

class AdminPortal : public QWidget
{
    Q_OBJECT

public:
    explicit AdminPortal(QWidget *parent = 0);
    ~AdminPortal();

private:
    Ui::AdminPortal *ui;
};

#endif // ADMINPORTAL_H
