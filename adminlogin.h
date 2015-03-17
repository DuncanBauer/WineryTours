#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QWidget>
#include "adminportal.h"

namespace Ui {
class adminLogin;
}

class adminLogin : public QWidget
{
    Q_OBJECT

public:
    explicit adminLogin(QWidget *parent = 0);
    ~adminLogin();

private slots:
    void on_pushButton_2_clicked();

    void on_login_clicked();

private:
    Ui::adminLogin *ui;
};

#endif // ADMINLOGIN_H
