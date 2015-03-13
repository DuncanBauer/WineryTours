#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "List.h"
#include "shorttour.h"
//#include "Wine.h"
#include "customtour.h"
#include "fulltour.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Custom_clicked();

    void on_Short_clicked();

    void on_Full_clicked();
    
private:
    Ui::MainWindow *ui;
    shortTour* shortWindow;
    CustomTour* customWindow;
    FullTour* fullWindow;
};

#endif // MAINWINDOW_H
