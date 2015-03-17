#ifndef VECTORWRAPPER_H
#define VECTORWRAPPER_H

#include <vector>
#include "Wine.h"

template <class type>
struct wines
{
    type data;
    int  numOf;
};

template <class type>
class newVector
{
private:
    vector<wines<type> > theVector;

public:
    newVector();
    ~newVector();
    void pop_back();
    void push_back(type newData);
    int  size();

//    bool operator != (const )
};

template <class type>
newVector<type>::newVector()
{
}

template <class type>
newVector<type>::~newVector()
{
}

template <class type>
void newVector<type>::pop_back()
{
    theVector.pop_back();
}

template <class type>
void newVector<type>::push_back(type newData)
{
    wines<type>* tempWine;
    unsigned int index = 0;
    while(index < size() && tempWine != newData)
    {
        tempWine = &theVector.operator [](index);
        index++;
    }
    if(tempWine == newData)
    {
        tempWine->numOf++;
    }
    else
    {
        theVector.push_back(newData);
    }
}

template <class type>
int newVector<type>::size()
{
    return theVector.size();
}

#endif // VECTORWRAPPER_H
