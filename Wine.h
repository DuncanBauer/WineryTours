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
    void    Print();

private:
    QString name;
    int    year;
    float  price;
};

#endif // WINE_H
