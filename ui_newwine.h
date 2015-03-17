/********************************************************************************
** Form generated from reading UI file 'newwine.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWWINE_H
#define UI_NEWWINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newWine
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *name;
    QLineEdit *year;
    QLineEdit *price;
    QPushButton *add;
    QTableWidget *tableWidget;
    QPushButton *edit;
    QPushButton *delete_2;
    QPushButton *close;

    void setupUi(QWidget *newWine)
    {
        if (newWine->objectName().isEmpty())
            newWine->setObjectName(QStringLiteral("newWine"));
        newWine->resize(553, 300);
        label = new QLabel(newWine);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(360, 50, 46, 13));
        label_2 = new QLabel(newWine);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(360, 80, 46, 13));
        label_3 = new QLabel(newWine);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(360, 110, 46, 13));
        name = new QLineEdit(newWine);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(400, 50, 113, 20));
        year = new QLineEdit(newWine);
        year->setObjectName(QStringLiteral("year"));
        year->setGeometry(QRect(400, 80, 113, 20));
        price = new QLineEdit(newWine);
        price->setObjectName(QStringLiteral("price"));
        price->setGeometry(QRect(400, 110, 113, 20));
        add = new QPushButton(newWine);
        add->setObjectName(QStringLiteral("add"));
        add->setGeometry(QRect(360, 150, 71, 23));
        tableWidget = new QTableWidget(newWine);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(30, 40, 291, 192));
        edit = new QPushButton(newWine);
        edit->setObjectName(QStringLiteral("edit"));
        edit->setGeometry(QRect(450, 150, 71, 23));
        delete_2 = new QPushButton(newWine);
        delete_2->setObjectName(QStringLiteral("delete_2"));
        delete_2->setGeometry(QRect(400, 190, 81, 23));
        close = new QPushButton(newWine);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(240, 260, 75, 23));

        retranslateUi(newWine);

        QMetaObject::connectSlotsByName(newWine);
    } // setupUi

    void retranslateUi(QWidget *newWine)
    {
        newWine->setWindowTitle(QApplication::translate("newWine", "Form", 0));
        label->setText(QApplication::translate("newWine", "Name", 0));
        label_2->setText(QApplication::translate("newWine", "Year", 0));
        label_3->setText(QApplication::translate("newWine", "Price", 0));
        add->setText(QApplication::translate("newWine", "Add", 0));
        edit->setText(QApplication::translate("newWine", "Edit", 0));
        delete_2->setText(QApplication::translate("newWine", "Delete", 0));
        close->setText(QApplication::translate("newWine", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class newWine: public Ui_newWine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWWINE_H
