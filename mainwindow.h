#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

    void on_Admin_clicked();

private:
    Ui::MainWindow *ui;
    vector<Winery> WineryVector;
    shortTour*     shortWindow;
    FullTour*      fullWindow;
    CustomTour*    customWindow;
    AdminPortal*   adminWindow;
};

#endif // MAINWINDOW_H
