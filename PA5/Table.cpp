// Name: Shuna Ye
// USC NetID: 2418710997
// CSCI 455 PA5
// Fall 2019

// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

using namespace std;


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
   hashTable = new ListType[HASH_SIZE]();
   hashSize = HASH_SIZE;
}


Table::Table(unsigned int hSize) {
   hashTable = new ListType[hSize]();
   hashSize = hSize;
}


int * Table::lookup(const string &key) {

   return listLookup(hashTable[hashCode(key)], key);   
}

bool Table::remove(const string &key) {
   return listRemove(hashTable[hashCode(key)], key);   
}

bool Table::insert(const string &key, int value) {
   if（this->lookup(key))
   {
      return false;
   }
   return listInsert(hashTable[hashCode(key)], key, value);   
}

int Table::numEntries() const {
   int num = 0;
   for (int i = 0; i < hashSize; i++)
   {
      num += listLength(hashTable[i]);
   }
   return num;       
}


void Table::printAll() const {
   for (int i = 0; i < hashSize; i++)
   {
      listPrint(hashTable[i]);
   }
}



void Table::hashStats(ostream &out) const {
   cout << "number of buckets: " << hashSize;
   cout << "number of entries: " << numEntries;
   cout << "number of non-empty buckets: " << ;
   cout << "longest chain: " << ;
}


// add definitions for your private methods here
int Table::numBucket() const 
{
   int num = 0;
   for (int i = 0; i < hashSize; i++)
   {
      if (hashTable[i] != NULL)
      {
         num++;
      }
   }
   return num;
}

