// Name:
// USC NetID:
// CSCI 455 PA5
// Spring 2019

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

Table::Table()
{
   hashTable = new ListType[HASH_SIZE]();
   hashSize = HASH_SIZE;
}

Table::Table(unsigned int hSize)
{
   hashTable = new ListType[hSize]();
   hashSize = hSize;
}

int *Table::lookup(const string &key)
{
   return listLookUp(hashTable[hashCode(key)], key); // dummy return value for stub
}

bool Table::remove(const string &key)
{
   return listRemove(hashTable[hashCode(key)], key); // dummy return value for stub
}

bool Table::insert(const string &key, int value)
{
   if (this->lookup(key))
   {
      return false;
   }
   listInsertFront(hashTable[hashCode(key)], key, value);
   return true;
}

int Table::numEntries() const
{
   int sum = 0;
   for (int i = 0; i < hashSize; i++)
   {
      sum += listLength(hashTable[i]);
   }
   return sum;
}

void Table::printAll() const
{
   for (int i = 0; i < hashSize; i++)
   {
      listPrintAll(hashTable[i]);
   }
}

void Table::hashStats(ostream &out) const
{
   cout << "number of buckets: " << hashSize << endl;
   cout << "number of entries: " << numEntries() << endl;
   cout << "number of non-empty buckets: " << numBuckets() << endl;
   cout << "longest chain: " << longestChain() << endl;
}

// add definitions for your private methods here
int Table::numBuckets() const
{
   int num = 0;
   for (int i = 0; i < hashSize; i++)
   {
      if (hashTable[i])
      {
         ++num;
      }
   }
   return num;
}

int Table::longestChain() const
{
   int longest = 0;
   int temp = 0;
   for (int i = 0; i < hashSize; i++)
   {
      temp = listLength(hashTable[i]);
      if (temp > longest)
      {
         longest = temp;
      }
   }
   return longest;
}