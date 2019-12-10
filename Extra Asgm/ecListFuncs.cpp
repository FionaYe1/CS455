/*  Name: Shuna Ye
 *  USC NetID: 2418710997
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

#define INT16_MIN -32768

void longestRun(ListType list, int & maxRunVal, int & maxRunLen) {
   ListType p = list;
   ListType pDup = list;      // second pointer to indicate how many numbers are dulplicated
   maxRunVal = p->data;    // assign the maxRunVal as the first data in the list
   maxRunLen = -1;         // initial the maxRunLen
   int tempLen;            // record the length if there is any duplicate numbers
   while (1)
   {
      tempLen = 0;
      pDup = p;
      while (pDup != NULL && p->data == pDup->data)   // calculate the length
      {
         tempLen++;
         pDup = pDup->next;
      }
      if (tempLen > maxRunLen)   // compare the length with the maxRunLen so far
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

   ListType newNode = new Node(INT16_MIN, list);   // create a dummy node
   list = newNode;
   ListType p = list;
   ListType temp = list;

   while (p != NULL)
   {
      if (p->data % 3 == 0)
      {
         temp->next = p->next;
         delete p;               // delete the node if it is the multiple of 3
         p = temp->next;
         continue;
      }
      temp = p;
      p = p->next;
   }
   list = newNode->next;
   delete newNode;            // delete the dummy node
}


void insertMiddle(ListType & list, int midVal) {
   ListType midNode = new Node(midVal);      // create the node whose data is midVal
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
   ListType newGuy = NULL;    // create a dummy node

   if (p1 == NULL)
   {
      return p2;
   }
   if (p2 == NULL)
   {
      return p1;
   }
   // choose the minimum node as the first node
   if (p1->data > p2->data)   
   {
      newGuy = p2;      // connect the minimun node
      p2 = p2->next;
   }
   else if (p1->data < p2->data)
   {
      newGuy = p1;
      p1 = p1->next;
   }
   else if (p1->data == p2->data)
   {
      newGuy = p1;
      p1 = p1->next;
      temp = p2->next;  // delete another node to prevent the memory leaks
      delete p2;
      p2 = temp;
   }
   ListType resultList = newGuy;     // record the first node

   while(p1 != NULL && p2 != NULL)  
   {
      // compare the data of the first nodes in both lists
      if (p1->data > p2->data)   
      {
         newGuy->next = p2;      // connect the minimun node
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
         temp = p2->next;  // delete another node to prevent the memory leaks
         delete p2;
         p2 = temp;
      }
   }
   // If one of the lists are empty, connect another list to newGuy
   if (p1 == NULL)      
   {
      newGuy->next = p2;
   }
   else
   {
      newGuy->next = p1;
   }
   return resultList;  // dummy code so starter code compiles
}



