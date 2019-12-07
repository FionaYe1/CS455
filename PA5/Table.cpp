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

// returns the address of the value that goes with this key
// or NULL if key is not present.
//   Thus, this method can be used to either lookup the value or
//   update the value that goes with this key.
int * Table::lookup(const string &key) {

   return listLookup(hashTable[hashCode(key)], key);   
}

// remove a pair given its key
// false iff key wasn't present
bool Table::remove(const string &key) {
   return listRemove(hashTable[hashCode(key)], key);   
}

// insert a new pair into the table
// return false iff this key was already present
//         (and no change made to table)
bool Table::insert(const string &key, int value) {
   return listInsert(hashTable[hashCode(key)], key, value);   
}

// number of entries in the table
int Table::numEntries() const {
   int num = 0;
   for (int i = 0; i < hashSize; i++)
   {
      num += listLength(hashTable[i]);
   }
   return num;       
}

// print out all the entries in the table, one per line.
// Sample output:
//   zhou 283
//   sam 84
//   babs 99
void Table::printAll() const {
   for (int i = 0; i < hashSize; i++)
   {
      listPrint(hashTable[i]);
   }
}

// hashStats: for diagnostic purposes only
// prints out info to let us know if we're getting a good distribution
// of values in the hash table.
void Table::hashStats(ostream &out) const {
   out << "number of buckets: " << hashSize << endl;
   out << "number of entries: " << numEntries() << endl;
   out << "number of non-empty buckets: " << numBucket() << endl;
   out << "longest chain: " << longestChain() << endl;
}


// add definitions for your private methods here

// the number of the buckets in the table
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

// the length of the longest chain
int Table::longestChain() const
{
   int max = 0;
   for (int i = 0; i < hashSize; i++)
   {
      if (max < listLength(hashTable[i])) 
      {
         max = listLength(hashTable[i]);
      }
   }
   return max;
}
