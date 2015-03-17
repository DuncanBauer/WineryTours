/********************************************************************************
** Form generated from reading UI file 'responsewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESPONSEWINDOW_H
#define UI_RESPONSEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_responseWindow
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *responseWindow)
    {
        if (responseWindow->objectName().isEmpty())
            responseWindow->setObjectName(QStringLiteral("responseWindow"));
        responseWindow->resize(396, 158);
        label = new QLabel(responseWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 30, 251, 71));
        pushButton = new QPushButton(responseWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 120, 75, 23));
        pushButton->setMinimumSize(QSize(75, 23));
        pushButton->setMaximumSize(QSize(75, 23));

        retranslateUi(responseWindow);

        QMetaObject::connectSlotsByName(responseWindow);
    } // setupUi

    void retranslateUi(QWidget *responseWindow)
    {
        responseWindow->setWindowTitle(QApplication::translate("responseWindow", "Form", 0));
        label->setText(QApplication::translate("responseWindow", "TextLabel", 0));
        pushButton->setText(QApplication::translate("responseWindow", "Okay", 0));
    } // retranslateUi

};

namespace Ui {
    class responseWindow: public Ui_responseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESPONSEWINDOW_H
