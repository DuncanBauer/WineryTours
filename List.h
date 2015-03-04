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
    WineList(const WineList& list);
    ~WineList();

    void Add(Wine newWine);
    void Delete();
    void Empty();
    WineList<type>& operator =(WineList<type>& list);

    bool IsEmpty();
    int  Size();
    void Print();

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
WineList<type>::WineList(const WineList &list)
{
    node<type>* temp  = new node<type>();
    node<type>* temp2 = list.head;

    this->head = temp;
    this->tail = temp;
    this->size = list.size;

    while(temp2 != NULL)
    {
        temp->prev = NULL;
        temp->wine = temp2->wine;
        temp->next = new node<type>();

        temp2 = temp2->next;
        temp  = temp->next;
        tail  = tail->next;
    }
}

template <class type>
WineList<type>::~WineList()
{
    Empty();
}

template <class type>
void WineList<type>::Add(Wine newWine)
{
    node<type>* newNode = new node<type>();
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
WineList<type>& WineList<type>::operator =(WineList<type>& list)
{
    this->head = list.head;
    this->tail = list.tail;
    this->size = list.size;
    return *this;
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

template <class type>
void WineList<type>::Print()
{
    node<type>* temp = head;
    while(temp != NULL)
    {
        qDebug() << temp->wine.GetName();
        temp = temp->next;
    }
}

#endif // LIST_H
