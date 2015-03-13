#ifndef LIST_H
#define LIST_H

using namespace std;

#include "Wine.h"

template <class type>
struct node
{
    type  data;
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

    void Add(type newWine);
    void Delete();
    void Empty();
    WineList<type>& operator =(const WineList<type>& list);
    type operator [](int index);

    bool IsEmpty();
    int  Size();
    type GetData(int index);

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
WineList<type>::WineList(const WineList<type> &list)
{
    node<type>* temp  = new node<type>();
    node<type>* temp2 = list.head;

    temp->prev = NULL;
    this->head = temp;
    this->size = list.size;

    while(temp2 != NULL)
    {
        temp->data = temp2->data;
        temp->next = new node<type>();
        temp->next->prev = temp;

        temp2 = temp2->next;
        temp  = temp->next;
    }
    tail = temp->prev;
    temp->prev->next = NULL;
    delete temp;
}

template <class type>
WineList<type>::~WineList()
{
    Empty();
}

template <class type>
void WineList<type>::Add(type newData)
{
    node<type>* newNode = new node<type>();
    newNode->data       = newData;

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
    if(!IsEmpty())
    {
        node<type>* temp = head;
        head             = head->next;
        if(head != NULL)
        {
            head->prev = NULL;
        }
        else
        {
            tail = NULL;
        }
        delete temp;
        size--;
    }
}

template <class type>
void WineList<type>::Empty()
{
    node<type>* temp = head;
    while(!IsEmpty())
    {
        head = head->next;
        delete temp;
        temp = head;
    }
    tail = NULL;
    size = 0;
}

template <class type>
type WineList<type>::operator [](int index)
{
    type tempWine;
    if(index < size)
    {
        node<type>* temp = head;
        int jndex = 0;
        while(jndex < index)
        {
            temp = temp->next;
            jndex++;
        }
        tempWine = temp->data;
    }
    return tempWine;
}

template <class type>
WineList<type>& WineList<type>::operator =(const WineList<type>& list)
{
    this->Empty();

    node<type>* temp  = new node<type>();
    node<type>* temp2 = list.head;

    temp->prev = NULL;
    this->head = temp;
    this->size = list.size;

    while(temp2 != NULL)
    {
        temp->data = temp2->data;
        temp->next = new node<type>();
        temp->next->prev = temp;

        temp2 = temp2->next;
        temp  = temp->next;
    }
    tail = temp->prev;
    temp->prev->next = NULL;
    delete temp;
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
type WineList<type>::GetData(int index)
{
    node<type>* temp = head;
    for(int jndex = 0; jndex < index; index++)
    {
        temp = temp->next;
    }
    return temp->data;
}

#endif // LIST_H
