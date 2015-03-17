/********************************************************************************
** Form generated from reading UI file 'customtour.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMTOUR_H
#define UI_CUSTOMTOUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomTour
{
public:
    QPushButton *add;
    QListWidget *userList;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QPushButton *remove;

    void setupUi(QWidget *CustomTour)
    {
        if (CustomTour->objectName().isEmpty())
            CustomTour->setObjectName(QStringLiteral("CustomTour"));
        CustomTour->resize(511, 385);
        add = new QPushButton(CustomTour);
        add->setObjectName(QStringLiteral("add"));
        add->setGeometry(QRect(220, 160, 75, 23));
        userList = new QListWidget(CustomTour);
        userList->setObjectName(QStringLiteral("userList"));
        userList->setGeometry(QRect(300, 70, 181, 251));
        listWidget = new QListWidget(CustomTour);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(30, 70, 181, 251));
        pushButton = new QPushButton(CustomTour);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 340, 75, 23));
        remove = new QPushButton(CustomTour);
        remove->setObjectName(QStringLiteral("remove"));
        remove->setGeometry(QRect(220, 200, 75, 23));

        retranslateUi(CustomTour);

        QMetaObject::connectSlotsByName(CustomTour);
    } // setupUi

    void retranslateUi(QWidget *CustomTour)
    {
        CustomTour->setWindowTitle(QApplication::translate("CustomTour", "Form", 0));
        add->setText(QApplication::translate("CustomTour", "Add", 0));
        pushButton->setText(QApplication::translate("CustomTour", "Start Tour", 0));
        remove->setText(QApplication::translate("CustomTour", "Remove", 0));
    } // retranslateUi

};

namespace Ui {
    class CustomTour: public Ui_CustomTour {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMTOUR_H
