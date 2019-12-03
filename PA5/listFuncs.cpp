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

bool listInsert(ListType &list, string theKey, int theValue)
{
   list = new Node(theKey, theValue, list);
   return true;
}



bool listRemove(ListType &list, string target)
{
   if (!list)
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
   while (p)
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
}