#include <iostream>
#include "test.h"
#include <cassert>
#include <cstring>

int main(void) 
{
   Test * tests = new Test();
   tests->runUnitTests();

   string choice;
   string s;

   cout << "Would you like to quit(Q) or to calculate(C) ? " << endl;
   cin >> choice;

   Automate * automate = new Automate("");
   
   while(choice.compare("c") == 0)
   {
      cout << "What is the word to interpret ?" << endl;
      cin >> s;
      automate->reset(s);
      automate->analyse();
      cout << "Would you like to quit(Q) or to calculate(C) ? " << endl;
      cin >> choice;
   }

   cout << "Bye bye " << endl;

   delete tests;
   delete automate;
}