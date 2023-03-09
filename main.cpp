#include <iostream>
#include "test.h"
#include <cassert>


int main(void) 
{
   Test * tests = new Test();
   //tests->runUnitTests();

   cout << "What is the word to interpret ?" << endl;
   string s;
   cin >> s;

   Automate * automate = new Automate(s);
   automate->analyse();

   delete tests;
   delete automate;
}