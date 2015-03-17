#include "instructions.h"
#include "ui_instructions.h"

instructions::instructions(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::instructions)
{
    ui->setupUi(this);
}

instructions::instructions(QWidget *parent, QString title, QString message) :
    QWidget(parent),
    ui(new Ui::instructions)
{
    ui->setupUi(this);
    this->setWindowTitle(title);

    ui->label->sette(message);
    ui->label->setWordWrap(true);
    ui->label->setAlignment(Qt::AlignCenter);
}

instructions::~instructions()
{
    delete ui;
}

void instructions::on_close_clicked()
{
    this->close();
}
