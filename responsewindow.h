#ifndef RESPONSEWINDOW_H
#define RESPONSEWINDOW_H

#include <QWidget>
#include <QString>

namespace Ui {
class responseWindow;
}

class responseWindow : public QWidget
{
    Q_OBJECT

public:
    explicit responseWindow(QWidget *parent = 0);
    explicit responseWindow(QWidget *parent, QString title, QString message);
    ~responseWindow();

private:
    Ui::responseWindow *ui;
};

#endif // RESPONSEWINDOW_H
