/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *Admin;
    QLabel *RapeGrape;
    QLabel *Demise;
    QPushButton *Custom;
    QPushButton *Full;
    QPushButton *Short;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(481, 390);
        MainWindow->setStyleSheet(QStringLiteral("background-image: url(:/Downloads/WineRotator-2000x925.jpg);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Admin = new QPushButton(centralWidget);
        Admin->setObjectName(QStringLiteral("Admin"));
        Admin->setGeometry(QRect(340, 310, 131, 20));
        Admin->setStyleSheet(QLatin1String("color: white;\n"
"font: 13pt \"Papyrus\";"));
        RapeGrape = new QLabel(centralWidget);
        RapeGrape->setObjectName(QStringLiteral("RapeGrape"));
        RapeGrape->setGeometry(QRect(10, 10, 461, 151));
        RapeGrape->setStyleSheet(QStringLiteral("font: italic 36pt \"Zapfino\";"));
        Demise = new QLabel(centralWidget);
        Demise->setObjectName(QStringLiteral("Demise"));
        Demise->setGeometry(QRect(70, 140, 341, 61));
        Demise->setStyleSheet(QLatin1String("color: white;\n"
"font: 16pt \"Papyrus\";\n"
"\n"
"\n"
""));
        Custom = new QPushButton(centralWidget);
        Custom->setObjectName(QStringLiteral("Custom"));
        Custom->setGeometry(QRect(190, 210, 113, 32));
        QFont font;
        font.setFamily(QStringLiteral("Papyrus"));
        font.setPointSize(13);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        Custom->setFont(font);
        Custom->setStyleSheet(QLatin1String("color: white;\n"
"font: 13pt \"Papyrus\";\n"
""));
        Full = new QPushButton(centralWidget);
        Full->setObjectName(QStringLiteral("Full"));
        Full->setGeometry(QRect(190, 250, 113, 32));
        Full->setStyleSheet(QLatin1String("color: white;\n"
"font: 13pt \"Papyrus\";\n"
""));
        Short = new QPushButton(centralWidget);
        Short->setObjectName(QStringLiteral("Short"));
        Short->setGeometry(QRect(190, 290, 113, 32));
        Short->setStyleSheet(QLatin1String("color: white;\n"
"font: 13pt \"Papyrus\";\n"
""));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 481, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        Admin->setText(QApplication::translate("MainWindow", "Administrator", 0));
        RapeGrape->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">Rape Grape 2k15</span></p></body></html>", 0));
        Demise->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; color:#ffffff;\">          Please select your demise...</span></p></body></html>", 0));
        Custom->setText(QApplication::translate("MainWindow", "Custom Tour", 0));
        Full->setText(QApplication::translate("MainWindow", "Full Tour", 0));
        Short->setText(QApplication::translate("MainWindow", "Short Tour", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
