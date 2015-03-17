/********************************************************************************
** Form generated from reading UI file 'shorttour.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHORTTOUR_H
#define UI_SHORTTOUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_shortTour
{
public:
    QSpinBox *spinBox;
    QListWidget *listWidget;
    QPushButton *pushButton;

    void setupUi(QWidget *shortTour)
    {
        if (shortTour->objectName().isEmpty())
            shortTour->setObjectName(QStringLiteral("shortTour"));
        shortTour->resize(531, 381);
        spinBox = new QSpinBox(shortTour);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(310, 150, 42, 22));
        listWidget = new QListWidget(shortTour);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(40, 70, 161, 211));
        pushButton = new QPushButton(shortTour);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(224, 330, 81, 23));

        retranslateUi(shortTour);

        QMetaObject::connectSlotsByName(shortTour);
    } // setupUi

    void retranslateUi(QWidget *shortTour)
    {
        shortTour->setWindowTitle(QApplication::translate("shortTour", "Form", 0));
        pushButton->setText(QApplication::translate("shortTour", "Start Tour", 0));
    } // retranslateUi

};

namespace Ui {
    class shortTour: public Ui_shortTour {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHORTTOUR_H
