/********************************************************************************
** Form generated from reading UI file 'intour.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTOUR_H
#define UI_INTOUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inTour
{
public:
    QLabel *winaryName;
    QListWidget *wineList;
    QLabel *wines;
    QPushButton *purchWineButton;
    QPushButton *nextButton;
    QListWidget *wineListPurch;
    QLabel *winesPurch;
    QLabel *totalLabel;
    QLabel *totalInt;

    void setupUi(QWidget *inTour)
    {
        if (inTour->objectName().isEmpty())
            inTour->setObjectName(QStringLiteral("inTour"));
        inTour->resize(400, 300);
        winaryName = new QLabel(inTour);
        winaryName->setObjectName(QStringLiteral("winaryName"));
        winaryName->setGeometry(QRect(130, 10, 151, 16));
        wineList = new QListWidget(inTour);
        wineList->setObjectName(QStringLiteral("wineList"));
        wineList->setGeometry(QRect(45, 60, 111, 131));
        wines = new QLabel(inTour);
        wines->setObjectName(QStringLiteral("wines"));
        wines->setGeometry(QRect(50, 40, 91, 16));
        purchWineButton = new QPushButton(inTour);
        purchWineButton->setObjectName(QStringLiteral("purchWineButton"));
        purchWineButton->setGeometry(QRect(60, 200, 81, 23));
        nextButton = new QPushButton(inTour);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setGeometry(QRect(160, 260, 75, 23));
        wineListPurch = new QListWidget(inTour);
        wineListPurch->setObjectName(QStringLiteral("wineListPurch"));
        wineListPurch->setGeometry(QRect(240, 60, 111, 131));
        winesPurch = new QLabel(inTour);
        winesPurch->setObjectName(QStringLiteral("winesPurch"));
        winesPurch->setGeometry(QRect(240, 40, 91, 16));
        totalLabel = new QLabel(inTour);
        totalLabel->setObjectName(QStringLiteral("totalLabel"));
        totalLabel->setGeometry(QRect(250, 200, 71, 16));
        totalInt = new QLabel(inTour);
        totalInt->setObjectName(QStringLiteral("totalInt"));
        totalInt->setGeometry(QRect(330, 200, 46, 13));

        retranslateUi(inTour);

        QMetaObject::connectSlotsByName(inTour);
    } // setupUi

    void retranslateUi(QWidget *inTour)
    {
        inTour->setWindowTitle(QApplication::translate("inTour", "Form", 0));
        winaryName->setText(QApplication::translate("inTour", "<Current winery name>", 0));
        wines->setText(QApplication::translate("inTour", "Wines Available", 0));
        purchWineButton->setText(QApplication::translate("inTour", "Purchase Wine", 0));
        nextButton->setText(QApplication::translate("inTour", "Continue", 0));
        winesPurch->setText(QApplication::translate("inTour", "Wines Purchased", 0));
        totalLabel->setText(QApplication::translate("inTour", "Money Spent: ", 0));
        totalInt->setText(QApplication::translate("inTour", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class inTour: public Ui_inTour {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTOUR_H
