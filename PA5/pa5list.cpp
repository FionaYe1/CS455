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
   listPrint(head);

   listInsert(head, "123", 111);
   listInsert(head, "123", 222);
   listInsert(head, "123", 333);
   listPrint(head);

   cout << listRemove(head, "123") << endl;
   listPrint(head);
   listInsert(head, "123", 1);
   listInsert(head, "12", 2);
   listInsert(head, "1", 3);
   listPrint(head);

   listInsert(head, "123", 1);
   listInsert(head, "12", 2);
   listInsert(head, "1", 3);
   listInsert(head, "0", 4);
   listPrint(head);
   cout << *listLookup(head, "1") << endl;
   // cout << find(head, "123") << endl;

   listPrint(head);

   return 0;
}
