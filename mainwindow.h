#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD
//#include "List.h"
#include "shorttour.h"
//#include "Wine.h"
#include "customtour.h"
#include "fulltour.h"
=======
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <vector>
#include "ui_mainwindow.h"
#include "shorttour.h"
#include "fulltour.h"
#include "customtour.h"
#include "adminportal.h"
#include "List.h"
#include "Winery.h"
#include "customtour.h"
>>>>>>> a5d31d628648c32e2ec5fbecc714c02f71520129

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

<<<<<<< HEAD
=======

>>>>>>> a5d31d628648c32e2ec5fbecc714c02f71520129
private slots:
    void on_Custom_clicked();

    void on_Short_clicked();

    void on_Full_clicked();
<<<<<<< HEAD
    
private:
    Ui::MainWindow *ui;
    shortTour* shortWindow;
    CustomTour* customWindow;
    FullTour* fullWindow;
=======

    void on_Admin_clicked();

private:
    Ui::MainWindow *ui;
    vector<Winery> WineryVector;
    shortTour*     shortWindow;
    FullTour*      fullWindow;
    CustomTour*    customWindow;
    AdminPortal*   adminWindow;
>>>>>>> a5d31d628648c32e2ec5fbecc714c02f71520129
};

#endif // MAINWINDOW_H
