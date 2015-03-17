#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <QWidget>
#include <QString>

namespace Ui {
class instructions;
}

class instructions : public QWidget
{
    Q_OBJECT

public:
    explicit instructions(QWidget *parent = 0);
    explicit instructions(QWidget *parent, QString title, QString message);
    ~instructions();

private slots:
    void on_close_clicked();

private:
    Ui::instructions *ui;
};

#endif // INSTRUCTIONS_H
