#ifndef LIST_H
#define LIST_H

using namespace std;

#include "Wine.h"
#include <qdebug.h>

template <class type>
struct node
{
    type  data;
    int   quantity;
    node* next;
    node* prev;
};

template <class type>
class WineList
{
public:
    WineList();
    WineList(bool newIsCart);
    WineList(const WineList& list);
    ~WineList();

    void Add(type newWine);
    void Delete(int index);
    void Pop_back();
    void Empty();
    void SetCart(bool newIsCart);
    WineList<type>& operator =(const WineList<type>& list);
    type* operator [](int index);

    node<type>* GetHead();
    bool IsEmpty();
    int  Size();
    type* GetData(int index);

private:
    node<type>* head;
    node<type>* tail;
    int         size;
    bool        isCart;
};

template <class type>
WineList<type>::WineList()
{
    head = NULL;
    tail = NULL;
    size = 0;
    isCart = 0;
}

template <class type>
WineList<type>::WineList(bool newIsCart)
{
    head = NULL;
    tail = NULL;
    size = 0;
    isCart = newIsCart;
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
        temp->quantity = temp2->quantity;
        temp->next = new node<type>();
        temp->next->prev = temp;

        temp2 = temp2->next;
        temp  = temp->next;
    }
    tail = temp->prev;
    tail->next = NULL;
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
    if(size < 10)
    {
        node<type>* newNode = new node<type>();
        newNode->data       = newData;
        newNode->quantity   = 1;

        if(IsEmpty())
        {
            head = newNode;
            tail = newNode;
            newNode->next = NULL;
            newNode->prev = NULL;
            size++;
        }
        else if(!isCart)
        {
            tail->next    = newNode;
            newNode->prev = tail;
            newNode->next = NULL;
            tail          = tail->next;
            size++;
        }
        else
        {
            node<type>* temp  = head;
            bool        found = false;
            while(temp != NULL && !found)
            {
                if(temp->data == newNode->data)
                {
                    temp->quantity++;
                    found = true;
                }
                temp = temp->next;
            }
            if(!found)
            {
                tail->next    = newNode;
                newNode->prev = tail;
                newNode->next = NULL;
                tail          = tail->next;
                size++;
            }
            else
            {
                delete newNode;
            }
        }
    }
}

template <class type>
void WineList<type>::Delete(int index)
{
    if(!IsEmpty()&& index < size)
    {
        node<type>* temp = head;

        if(size == 1)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            int jndex = 0;
            while(jndex < index && temp != NULL)
            {
                temp = temp->next;
                jndex++;
            }

            if(temp == head)
            {
                head = head->next;
                if(head != NULL)
                {
                    head->prev = NULL;
                }
                else
                {
                    tail = NULL;
                }
            }
            else if(temp == tail)
            {
                tail = tail->prev;
                if(tail != NULL)
                {
                    tail->next = NULL;
                }
                else
                {
                    head = NULL;
                }
            }
            else if(temp == NULL)
            {
                temp = new node<type>();
            }
            else
            {
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
            }
        }
        delete temp;
        size--;
    }
}

template <class type>
void WineList<type>::Pop_back()
{
    if(!IsEmpty())
    {
        node<type>* temp = tail;
        tail             = tail->prev;
        if(tail != NULL)
        {
            tail->next = NULL;
        }
        else
        {
            head = NULL;
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
void WineList<type>::SetCart(bool newIsCart)
{
    isCart = newIsCart;
}

template <class type>
type* WineList<type>::operator [](int index)
{
    type* tempWine;
    if(index < size)
    {
        node<type>* temp = head;
        for(int jndex = 0; jndex < index; jndex++)
        {
            temp = temp->next;
        }
        tempWine = &temp->data;
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
        temp->quantity = temp2->quantity;
        temp->next = new node<type>();
        temp->next->prev = temp;

        temp2 = temp2->next;
        temp  = temp->next;
    }
    tail = temp->prev;
    tail->next = NULL;
    delete temp;
    return *this;
}

template <class type>
node<type>* WineList<type>::GetHead()
{
    return head;
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
type* WineList<type>::GetData(int index)
{
    node<type>* temp = head;
    // i am so dum
    for(int jndex = 0; jndex < index; jndex++)
    {
        temp = temp->next;
    }

    return &(temp->data);
}

#endif // LIST_H
