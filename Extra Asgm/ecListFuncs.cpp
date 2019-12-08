/*  Name:
 *  USC NetID:
 *  CS 455 Fall 2019
 *
 *  See ecListFuncs.h for specification of each function.
 */


// for NULL
#include <cstdlib>

// in case you want to use assert statements
#include <cassert>

#include "ecListFuncs.h"

using namespace std;


void longestRun(ListType list, int & maxRunVal, int & maxRunLen) {
   ListType p = list;
   ListType pDup = list;
   maxRunVal = p->data;
   maxRunLen = -1;
   int tempLen;
   while (1)
   {
      tempLen = 0;
      pDup = p;
      while (pDup != NULL &&p->data == pDup->data)
      {
         tempLen++;
         pDup = pDup->next;
      }
      if (tempLen > maxRunLen)
      {
         maxRunLen = tempLen;
         maxRunVal = p->data;
      }
      if(pDup==NULL){
         return;
      }
      p = pDup;
   }
}


void removeMultiplesOf3(ListType & list) {

   ListType newNode = new Node(INT16_MIN);   // create a dummy node
   newNode->next = list;
   list = newNode;
   ListType p = list;
   ListType temp = list;

   while (p != NULL)
   {
      if (p->data % 3 == 0)
      {
         temp->next = p->next;
         delete p;
         p = temp->next;
         continue;
      }
      temp = p;
      p = p->next;
   }
   list = newNode->next;
   delete newNode;
}


void insertMiddle(ListType & list, int midVal) {
   ListType midNode = new Node(midVal);   
   if (list == NULL || list->next == NULL)
   {
      midNode->next = list;
      list = midNode;
      return;
   }
   // calculate the length of the list
   ListType p = list;
   int len = 0;
   while (p != NULL)
   {
      len++;
      p = p->next;
   }
   int num = 0;
   p = list;
   // insert the midVal in the position of len/2
   while (num != len/2 - 1)
   {
      num++;
      p = p->next;
   }
   ListType temp = p->next;
   p->next = midNode;
   midNode->next = temp;
}


ListType merge(ListType list1, ListType list2) {
   ListType p1 = list1;
   ListType p2 = list2;
   ListType temp = list2;
   ListType newGuy = new Node(INT16_MIN);    // create a dummy node
   ListType resultList = newGuy;

   while(p1 != NULL && p2 != NULL)
   {
      if (p1->data > p2->data)
      {
         newGuy->next = p2;
         newGuy = newGuy->next;
         p2 = p2->next;
      }
      else if (p1->data < p2->data)
      {
         newGuy->next = p1;
         newGuy = newGuy->next;
         p1 = p1->next;
      }
      else if (p1->data == p2->data)
      {
         newGuy->next = p1;
         newGuy = newGuy->next;
         p1 = p1->next;
         temp = p2->next;
         delete p2;
         p2 = temp;
      }
   }
   if (p1 == NULL)
   {
      newGuy->next = p2;
   }
   else
   {
      newGuy->next = p1;
   }
   resultList = resultList->next;
   return resultList;  // dummy code so starter code compiles
}



