#include "List.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow MainProgramWindow;
    MainProgramWindow.show();

    return a.exec();
}

