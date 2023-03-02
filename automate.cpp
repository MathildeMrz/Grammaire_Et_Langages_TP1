#include <iostream>
#include "automate.h"

Automate::Automate(string chaine)
{
    cout << "Automate constructor " << endl;
    this->lexer = new Lexer(chaine);
    E0 * startState = new E0();
    stateStack.push_back(startState);
}

bool Automate::analyse()
{
    //Création d'un pointeur sur le symbole courant du mot à analyser
   Symbole * s;

    //Tant qu'il n'y a pas d'erreur
   while(*(s=this->lexer->Consulter())!=FIN) {
        //Affichage du symbole courant
        s->Affiche();
        cout<<endl;
        this->lexer->Avancer();
        
        if(*s == ERREUR)
        {
            cout << "Syntaxe incorrecte : le mot n'existe pas" << endl;
            return 0;
        }

        //stateStack.front() : état courant et s : symbole courant
        stateStack.front()->transition(*(this), s);        
   }   

   cout << "Syntaxe correcte : le mot existe" << endl;
   return 1;
}

void Automate::decalage(Symbole * s, State * e) 
{    
    if (s->isTerminal()) {
        lexer->Avancer();
    }

    symbolStack.push_back(s);
    stateStack.push_back(e);
}

void Automate::reduction(int n, Symbole * s) 
{
    for (int i=0;i<n;i++)
    {
        delete(stateStack.back());
        stateStack.pop_back();
    }
    //Nouvelle instance
    stateStack.back()->transition(*this,s);
}