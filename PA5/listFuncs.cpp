// Name: Shuna Ye
// USC NetID: 2418710997
// CSCI 455 PA5
// Fall 2019

#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
   key = theKey;
   value = theValue;
   next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
   key = theKey;
   value = theValue;
   next = n;
}




//*************************************************************************
// put the function definitions for your list functions below

// insert a new pair into the list
// return false iff this key was already present(and no change made to list)
bool listInsert(ListType &list, const string &theKey, int theValue)
{
   if (listLookup(list, theKey) != NULL)
   {
      return false;
   }
   list = new Node(theKey, theValue, list);
   return true;
}

// remove a pair given its key
// false iff key wasn't present
bool listRemove(ListType &list, const string &target)
{
   if (list == NULL)
   {
      return false;
   }
   ListType p = list;
   if (p->key == target)
   {
      ListType temp = p;
      list = temp->next;
      delete temp;
      return true;
   }
   ListType p2 = list;
   while (p != NULL)
   {
      if (p->key == target)
      {
         p2->next = p->next;
         delete p;
         return true;
      }
      p2 = p;
      p = p->next;
   }
   return false;
}

// print out all the entries in the list, one per line.
void listPrint(ListType &list)
{
   ListType p = list;
   while (p != NULL)
   {
      cout << p->key << ": " << p->value << endl;
      p = p->next;
   }
}

// returns the address of the value that goes with this key
// or NULL if key is not present.
//   Thus, this method can be used to either lookup the value or
//   update the value that goes with this key.
int *listLookup(ListType &list, const string &target)
{
   if (list == NULL)
   {
      return NULL;
   }
   ListType p = list;
   while (p != NULL)
   {
      if (p->key == target)
      {
         return &(p->value);
      }
      p = p->next;
   }
   return NULL;
}

// number of entries in the list
int listLength(ListType &list)
{
   ListType p = list;
   int length = 0;
   while (p != NULL)
   {
      length++;
      p = p->next;
   }
   return length;
}