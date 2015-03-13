#include "deletewine.h"
#include "ui_deletewine.h"

deleteWine::deleteWine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deleteWine)
{
    ui->setupUi(this);
}

deleteWine::~deleteWine()
{
    delete ui;
}
