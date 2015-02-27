#ifndef WINE_H
#define WINE_H

#include <QString>

class Wine
{
public:
    Wine();
    ~Wine();

    void SetName (QString newName);
    void SetYear (int     newYear);
    void SetPrice(float   newPrice);

    QString GetName();
    int     GetYear();
    float   GetPrice();

private:
    QString name;
    int    year;
    float  price;
};

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

#endif // WINE_H
