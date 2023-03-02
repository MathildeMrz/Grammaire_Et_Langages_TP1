#include <iostream>
#include "automate.h"


int main(void) {
   //string chaine("(1+34)*123");
   cout << "Quel est le mot à interpréter ? " << endl;
   string chaine;
   cin >> chaine;
   Automate * automate = new Automate(chaine);
   automate->analyse();
   return 0;
}