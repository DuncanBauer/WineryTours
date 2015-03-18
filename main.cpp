#include "List.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    WineList<int> list;
    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.Delete(0);
    list.Delete(0);
    list.Delete(0);
    list.Delete(0);
    QApplication a(argc, argv);
    MainWindow MainProgramWindow;
    MainProgramWindow.show();

    return a.exec();
}

