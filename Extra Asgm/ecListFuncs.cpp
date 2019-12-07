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

}


void insertMiddle(ListType & list, int midVal) {
   
}


ListType merge(ListType list1, ListType list2) {
   return NULL;  // dummy code so starter code compiles
}



