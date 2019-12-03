// Name:
// USC NetID:
// CSCI 455 PA5
// Spring 2019

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

using namespace std;

void help();
int main(int argc, char *argv[])
{

   // gets the hash table size from the command line

   int hashSize = Table::HASH_SIZE;

   Table *grades; // Table is dynamically allocated below, so we can call
   // different constructors depending on input from the user.

   if (argc > 1)
   {
      hashSize = atoi(argv[1]); // atoi converts c-string to int

      if (hashSize < 1)
      {
         cout << "Command line argument (hashSize) must be a positive number"
              << endl;
         return 1;
      }

      grades = new Table(hashSize);
   }
   else // no command line args given -- use default table size
   {
      grades = new Table();
   }

   grades->hashStats(cout);

   // add more code here
   // Reminder: use -> when calling Table methods, since grades is type Table*
   string command = ""; // save command
   bool flag = true; // to exit
   string name = ""; // save name
   int score = -1; // save score

   while (flag)
   {
      cout << "cmd>" << endl;
      cin >> command;
      if (command == "insert")
      {

         cin >> name;  
         cin >> score; 
         bool r = grades->insert(name, score);
         if (!r)
         {
            cout << "The student is already in the table. " << endl;
         }
      }
      else if (command == "change")
      {

         cin >> name; 
         cin >> score; 

         if (!grades->lookup(name)) // can't find
         {
            cout << "Name doesn't exist." << endl;
         }
         else
         {
            *(grades->lookup(name)) = score;
         }
      }
      else if (command == "lookup")
      {

         cin >> name; 
         if (!grades->lookup(name)) // can't find
         {
            cout << "Name doesn't exist." << endl;
         }
         else
         {
            cout << name << ": " << *(grades->lookup(name)) << endl;
         }
      }
      else if (command == "remove")
      {

         cin >> name; 
         bool r = grades->remove(name);
         if(!r){ // can't find
            cout<<"The student doesn't exist "<<endl;
         }
      }
      else if (command == "print")
      {
         grades->printAll();
      }
      else if (command == "size")
      {
         cout << grades->numEntries() << endl;
      }
      else if (command == "stats")
      {
         grades->hashStats(cout);
      }
      else if (command == "help")
      {
         help();
      }
      else if (command == "quit")
      {
         flag = false; ////exit
      }
      else
      {
         cout << "ERROR: invalid command" << endl;
         help();
      }
   }

   return 0;
}

// print
// the help information
void help()
{
   cout << "insert name score:Insert this name and score in the grade table. If this name was already present, print a message to that effect, and don't do the insert." << endl;
   cout << "change name newscore:Lookup the name, and print out his or her score, or a message indicating that student is not in the table." << endl;
   cout << "remove name:Remove this student. If this student wasn't in the grade table, print a message to that effect." << endl;
   cout << "print:Prints out all names and scores in the table." << endl;
   cout << "size:Prints out the number of entries in the table." << endl;
   cout << "stats:Prints out statistics about the hash table at this point. (Calls hashStats() method)" << endl;
   cout << "help:Prints out a brief command summary." << endl;
   cout << "quit:Exits the program." << endl;
}
