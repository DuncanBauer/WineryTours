/********************************************************************************
** Form generated from reading UI file 'adminportal.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPORTAL_H
#define UI_ADMINPORTAL_H

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

class Ui_AdminPortal
{
public:
    QPushButton *addWinery;
    QPushButton *editList;
    QListWidget *wineries;
    QListWidget *pendingWineries;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QWidget *AdminPortal)
    {
        if (AdminPortal->objectName().isEmpty())
            AdminPortal->setObjectName(QStringLiteral("AdminPortal"));
        AdminPortal->resize(420, 300);
        addWinery = new QPushButton(AdminPortal);
        addWinery->setObjectName(QStringLiteral("addWinery"));
        addWinery->setGeometry(QRect(284, 230, 71, 23));
        editList = new QPushButton(AdminPortal);
        editList->setObjectName(QStringLiteral("editList"));
        editList->setGeometry(QRect(60, 230, 81, 23));
        wineries = new QListWidget(AdminPortal);
        wineries->setObjectName(QStringLiteral("wineries"));
        wineries->setGeometry(QRect(30, 30, 141, 192));
        pendingWineries = new QListWidget(AdminPortal);
        pendingWineries->setObjectName(QStringLiteral("pendingWineries"));
        pendingWineries->setGeometry(QRect(250, 30, 141, 192));
        label = new QLabel(AdminPortal);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 61, 16));
        label_2 = new QLabel(AdminPortal);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(250, 10, 121, 16));
        pushButton = new QPushButton(AdminPortal);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 260, 61, 23));

        retranslateUi(AdminPortal);

        QMetaObject::connectSlotsByName(AdminPortal);
    } // setupUi

    void retranslateUi(QWidget *AdminPortal)
    {
        AdminPortal->setWindowTitle(QApplication::translate("AdminPortal", "Form", 0));
        addWinery->setText(QApplication::translate("AdminPortal", "Add Winery", 0));
        editList->setText(QApplication::translate("AdminPortal", "Edit Wine List", 0));
        label->setText(QApplication::translate("AdminPortal", "Wineries:", 0));
        label_2->setText(QApplication::translate("AdminPortal", "Pending Wineries:", 0));
        pushButton->setText(QApplication::translate("AdminPortal", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class AdminPortal: public Ui_AdminPortal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPORTAL_H
