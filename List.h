#ifndef LIST_H
#define LIST_H

using namespace std;

#include "Wine.h"

template <class type>
struct node
{
    type  wine;
    node* next;
    node* prev;
};

template <class type>
class WineList
{
public:
    WineList();
    ~WineList();

    void Add(node newNode);
    void Delete();
    void Empty();

    bool IsEmpty();
    int  Size();

private:
    node<type>* head;
    node<type>* tail;
    int         size;
};

template <class type>
WineList<type>::WineList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

template <class type>
WineList<type>::~WineList()
{
    Empty();
}

template <class type>
void WineList<type>::Add(Wine newWine)
{
    node<type>* newNode = new node<type();
    newNode->wine       = newWine;

    if(IsEmpty())
    {
        head = newNode;
        tail = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    else
    {
        tail->next    = newNode;
        newNode->prev = tail;
        newNode->next = NULL;
        tail          = tail->next;
    }
    size++;
}

template <class type>
void WineList<type>::Delete()
{
    node<type>* temp = head;
    head             = head->next;
    head->prev       = NULL;
    delete temp;
    size--;
}

template <class type>
void WineList<type>::Empty()
{
    while(head != NULL)
    {
        Delete();
    }
}

template <class type>
bool WineList<type>::IsEmpty()
{
    return head == NULL;
}

template <class type>
int WineList<type>::Size()
{
    return size;
}

#endif // LIST_H
