#include "Wine.h"
#include <QDebug>

Wine::Wine()
{
    name  = "";
    price = 0.0;
    year  = 0;
}

Wine::~Wine()
{
}

void Wine::SetName(QString newName)
{
    name = newName;
}

void Wine::SetYear(int newYear)
{
    year = newYear;
}

void Wine::SetPrice(float newPrice)
{
    price = newPrice;
}

QString Wine::GetName()
{
    return name;
}

int Wine::GetYear()
{
    return year;
}

float Wine::GetPrice()
{
    return price;
}

void Wine::Print()
{
    qDebug() << name  << endl
             << year  << endl
             << price << endl;
}

bool Wine::operator ==(const Wine& obj) const
{
    if(name == obj.name && price == obj.price && year == obj.year)
    {
        return true;
    }
    else
    {
        return false;
    }
}
