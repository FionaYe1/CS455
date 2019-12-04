// Name: Shuna Ye
// USC NetID: 2418710997
// CSCI 455 PA5
// Fall 2019

//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.

// Note2: it's good practice to not put "using" statement in *header* files.  Thus
// here, things from std libary appear as, for example, std::string

#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H
  

struct Node {
   std::string key;
   int value;

   Node *next;

   Node(const std::string &theKey, int theValue);

   Node(const std::string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.

// insert a new pair into the list
// return false iff this key was already present(and no change made to list)
bool listInsert(ListType &list, std::string theKey, int theValue);

// remove a pair given its key
// false iff key wasn't present
bool listRemove(ListType &list, std::string target);

void listPrint(ListType &list);

void listClear(ListType &list);

// returns the address of the value that goes with this key
// or NULL if key is not present.
//   Thus, this method can be used to either lookup the value or
//   update the value that goes with this key.
int *listLookup(ListType &list, std::string target);

int listLength(ListType list);



// keep the following line at the end of the file
#endif
