#include "symbole.h"

Symbole::~Symbole(){};
Entier::~Entier(){};
Expr::~Expr(){};
OpenPar::~OpenPar(){};
ClosePar::~ClosePar(){};
Plus::~Plus(){};
Mult::~Mult(){};
Fin::~Fin(){};
Erreur::~Erreur(){};

int Symbole::getValue() 
{ 
   return -1;
}

int Entier::getValue() 
{ 
   return valeur;
}

int Expr::getValue()
{ 
   return valeur;
}

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

void Expr::Affiche() {
   Symbole::Affiche();
   cout<<valeur;
}

void OpenPar::Affiche() {
   Symbole::Affiche();
   cout<<"(";
}

void ClosePar::Affiche() {
   Symbole::Affiche();
   cout<<")";
}

void Plus::Affiche() {
   Symbole::Affiche();
   cout<<"+";
}

void Mult::Affiche() {
   Symbole::Affiche();
   cout<<"*";
}

void Fin::Affiche() {
   Symbole::Affiche();
   cout<<"FIN";
}

void Erreur::Affiche() {
   Symbole::Affiche();
   cout<<"aaERREUR";//TODO à quoi ca sert??
}