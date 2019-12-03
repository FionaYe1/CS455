// Name:
// USC NetID:
// CSCI 455 PA5
// Spring 2019

#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue)
{
    key = theKey;
    value = theValue;
    next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n)
{
    key = theKey;
    value = theValue;
    next = n;
}

//*************************************************************************
// put the function definitions for your list functions below

// Print
// all the items in the list
void listPrintAll(ListType list)
{
    while (list)
    {
        cout << list->key << " " << list->value << endl;
        list = list->next;
    }
}

// void printLast(ListType list)
// {
//     if (!list)
//     {
//         cout << endl;
//         return;
//     }
//     while (list->next)
//     {
//         list = list->next;
//     }
//     cout << list->value << endl;
// }

// insert an item in the front of the list
// Return true iff success
bool listInsertFront(ListType &list, const std::string &theKey, int theValue)
{
    list = new Node(theKey, theValue, list);
    return true;
}

// bool removeFront(ListType &list)
// {
//     if (!list)
//         return false;
//     ListType head = list;
//     delete head;
//     list = list->next;
//     return true;
// }

// bool removeLast(ListType &list)
// {
//     if (!list)
//         return false;
//     if (!list->next)
//     {
//         delete list;
//         list = NULL;
//         return true;
//     }
//     ListType p = list;
//     while (p->next->next)
//     {
//         p = p->next;
//     }
//     delete p->next;
//     p->next = NULL;
//     return true;
// }

// remove the item with theKey
// returen true iff remove successfully
bool listRemove(ListType &list, const std::string &theKey)
{
    if (!list)
        return false;
    ListType p = list;
    if (p->key == theKey)
    {
        ListType temp = list;
        list = temp->next;
        delete temp;
        return true;
    }
    ListType pre = NULL;
    while (p)
    {
        if (p->key == theKey)
        {
            pre->next = p->next;
            delete p;
            return true;
        }
        pre = p;
        p = p->next;
    }
    return false;
}

// bool removeAll(ListType &list)
// {
//     if (!list)
//         return false;
//     ListType p = list->next;
//     while (p)
//     {
//         delete list;
//         list = p;
//         p = p->next;
//     }
//     delete list;
//     list = NULL;
//     return true;
// }

// lookup the item with theKey
// return the pointer
// return NULL iff can't find
int *listLookUp(ListType &list, const string &theKey)
{
    if (!list)
        return NULL;
    ListType p = list;
    while (p)
    {
        if (p->key == theKey)
        {
            return &(p->value);
        }
        p = p->next;
    }
    return NULL;
}

// bool modify(ListType &list, const std::string &theKey, int theValue)
// {
//     if (!list)
//     {
//         listInsertFront(list, theKey, theValue);
//         return false;
//     }
//     ListType p = list;
//     while (p)
//     {
//         if (p->key == theKey)
//         {
//             p->value = theValue;
//             return true;
//         }
//         p = p->next;
//     }
//     listInsertFront(list, theKey, theValue);
//     return false;
// }

// return
// the length of the list
int listLength(ListType &list)
{
    ListType p = list;
    int num = 0;
    while (p)
    {
        ++num;
        p = p->next;
    }
    return num;
}