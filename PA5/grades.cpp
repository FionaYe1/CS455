// Name: Shuna Ye
// USC NetID: 2418710997
// CSCI 455 PA5
// Fall 2019

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

void doCommand(Table *grades, string input);
// void noNameFound(Table *grades,string name);
void help();

int main(int argc, char * argv[]) {

   // gets the hash table size from the command line

   int hashSize = Table::HASH_SIZE;

   Table * grades;  // Table is dynamically allocated below, so we can call
   // different constructors depending on input from the user.

   if (argc > 1) {
      hashSize = atoi(argv[1]);  // atoi converts c-string to int

      if (hashSize < 1) {
         cout << "Command line argument (hashSize) must be a positive number" 
              << endl;
         return 1;
      }

      grades = new Table(hashSize);

   }
   else {   // no command line args given -- use default table size
      grades = new Table();
   }


   grades->hashStats(cout);

   // add more code here
   // Reminder: use -> when calling Table methods, since grades is type Table*
   string input = "";
   bool quit = false;       // indicates to exit
   string name = "";
   int score = -1;

   while (!quit)
   {
      cout << "cmd>" << endl;
      cin >> input;
      // doCommand(grades, input);
      if (input == "insert")
      {
         cin >> name;
         cin >> score;
         if (!(grades->insert(name, score)))
         {
            cout << "ERROR: The student has already been in the table." << endl;
         }
      }
      else if (input == "change")
      {
         cin >> name;
         cin >> score;
         if (!grades->lookup(name))
         {
            cout << "ERROR: The student doesn't exist." << endl;
         }
         else
         {
            grades->remove(name);
            grades->insert(name, score);
         }
      }
      else if (input == "lookup")
      {
         cin >> name;
         if (!grades->lookup(name))
         {
            cout << "ERROR: The student doesn't exist." << endl;
         }
         else
         {
            cout << name << ": " << *(grades->lookup(name)) << endl;
         }
      }
      else if (input == "remove")
      {
         cin >> name;
         if (!grades->lookup(name))
         {
            cout << "ERROR: The student doesn't exist." << endl;
         }
         else
         {
            grades->remove(name);
         }
      }
      else if (input == "print")
      {
         grades->printAll();
      }
      else if (input == "size")
      {
         cout << grades->numEntries() << endl;
      }
      else if (input == "stats")
      {
         grades->hashStats(cout);
      }
      else if (input == "help")
      {
         help();
      }
      else if (input == "quit")
      {
         quit = true; // exit
      }
      else 
      {
         cout << "ERROR: invalid command" << endl;
         help();
      }
   }

   return 0;
}

void help()
{
   cout << "insert name score: Insert this name and score in the grade table.If this name was already present, print a message to that effect, and don't do the insert." << endl;
   cout << "change name newscore: Change the score for name. Print an appropriate message if this name isn't present." << endl;
   cout << "lookup name: Lookup the name, and print out his or her score, or a message indicating that student is not in the table." << endl;
   cout << "remove name: Remove this student. If this student wasn't in the grade table, print a message to that effect." << endl;
   cout << "print: Prints out all names and scores in the table." << endl;
   cout << "size: Prints out the number of entries in the table." << endl;
   cout << "stats: Prints out statistics about the hash table at this point.(Calls hashStats() method)" << endl;
   cout << "help: Prints out a brief command summary." << endl;
   cout << "quit: Exits the program." << endl;
}
