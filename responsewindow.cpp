#include "responsewindow.h"
#include "ui_responsewindow.h"

responseWindow::responseWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::responseWindow)
{
    ui->setupUi(this);
}

responseWindow::responseWindow(QWidget *parent, QString title, QString message) :
    QWidget(parent),
    ui(new Ui::responseWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(title);
    ui->label->setText(message);
    // Enables word wrapping within label
    ui->label->setWordWrap(true);
    // Centers the text in the window
    ui->label->setAlignment(Qt::AlignCenter);
}

responseWindow::~responseWindow()
{
    delete ui;
}

void responseWindow::on_pushButton_clicked()
{
    this->close();
}
