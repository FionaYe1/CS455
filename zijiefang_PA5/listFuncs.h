// Name:
// USC NetID:
// CSCI 455 PA5
// Spring 2019

//*************************************************************************
// Node class definition
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.

// Note2: it's good practice to not put "using" statement in *header* files.  Thus
// here, things from std libary appear as, for example, std::string

#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

struct Node
{
    std::string key;
    int value;

    Node *next;

    Node(const std::string &theKey, int theValue);

    Node(const std::string &theKey, int theValue, Node *n);
};

typedef Node *ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.

void listPrintAll(ListType list);

// void printLast(ListType list);

bool listInsertFront(ListType &list, const std::string &theKey, int theValue);

// bool removeFront(ListType &list);

// bool removeLast(ListType &list);

// bool removeAll(ListType &list);

bool listRemove(ListType &list,const std::string &theKey);

int *listLookUp(ListType &list, const std::string &theKey);

// bool modify(ListType &list, const std::string &theKey, int theValue);

int listLength(ListType &list);
// keep the following line at the end of the file
#endif
