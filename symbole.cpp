#include "symbole.h"

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

bool Symbole::isTerminal()
{
   //Implémenter
   return 0; 
}