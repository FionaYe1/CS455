// Name:
// USC NetID:
// CS 455 PA5
// Spring 2019

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"

int main()
{
   ListType head = NULL;
   listPrintAll(head);
   printLast(head);
   cout<<removeFront(head)<<endl;
   removeLast(head);
   listInsertFront(head, "123", 111);
   listInsertFront(head, "123", 222);
   listInsertFront(head, "123", 333);
   listPrintAll(head);
   printLast(head);
   cout<<removeLast(head)<<endl;
   listPrintAll(head);
   removeLast(head);
   listPrintAll(head);
   removeLast(head);
   listPrintAll(head);
   listInsertFront(head, "123", 1);
   listInsertFront(head, "12", 2);
   listInsertFront(head, "1", 3);
   listPrintAll(head);
   removeAll(head);
   listPrintAll(head);
   listInsertFront(head, "123", 1);
   listInsertFront(head, "12", 2);
   listInsertFront(head, "1", 3);
   listInsertFront(head, "0", 4);
   listPrintAll(head);
   cout << *listLookUp(head, "1") << endl;
   // cout << find(head, "123") << endl;
   modify(head,"123",21313);
   listPrintAll(head);
   modify(head,"12213213",3133);
   listPrintAll(head);
   return 0;
}
