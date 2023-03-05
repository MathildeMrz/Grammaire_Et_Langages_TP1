#include <iostream>
#include "automate.h"

Automate::Automate(string chaine)
{
    //cout << "Automate constructor " << endl;
    this->lexer = new Lexer(chaine);
    E0 * startState = new E0();
    stateStack.push_back(startState);
}

bool Automate::analyse()
{
    //Création d'un pointeur sur le symbole courant du mot à analyser
    Symbole * s;

    //Tant qu'on n'arrive pas à la fin du mot
    while(*(s=this->lexer->Consulter())!=FIN) 
    {
        //Affichage du symbole courant. La tête de lecture a été incrémentée pour le prochain passage de la boucle while
        s->Affiche();
        cout<<endl;
        this->lexer->Avancer();

        cout << "----------------------stateStack----------------------" << endl;
        for(int i = 0; i <stateStack.size(); ++i)
        {
            stateStack.at(i)->print();
        }

        cout << "----------------------symbolStack----------------------" << endl;
        for(int i = 0; i <symbolStack.size(); ++i)
        {
            cout << symbolStack.at(i)->getIdent();
        }


        //Transition entre l'état actuel et le symbole lu
        stateStack.back()->transition(*(this), s);     

        if(*s == ERREUR)
        {
            cout << "Syntaxe incorrecte : le mot n'existe pas" << endl;
            return 0;
        }   
    }  

    cout << "Syntaxe correcte : le mot existe" << endl;
    return 1;
}

//on est dans l'état e (qui n'est pas un puit) et on lit le symbole s
void Automate::decalage(Symbole * s, State * e) 
{    
    //ajout du symbole et de l'état à leur pile respective
    symbolStack.push_back(s);
    stateStack.push_back(e);

    /*if (s->isTerminal()) 
    {
        lexer->Avancer();
    }*/
}

//s : symbole terminal qui vient d'être lu
void Automate::reduction(int n, Symbole * s) 
{
    cout << "Réduction " << endl;
    int ident = -1;

    //on dépile les n états
    cout << "On dépile " << n << " états" << endl;
    for (int i=0;i<n;i++)
    {
        if(i == 0)
        {
            ident = symbolStack.back()->getIdent();
        }
        cout << "Le symbole " << symbolStack.back()->getIdent() << " a été dépilé" << endl;
        cout << "L'état ";
        stateStack.back()->print();
        cout << " a été dépilé" << endl;

        delete(symbolStack.back());
        symbolStack.pop_back();

        delete(stateStack.back());
        stateStack.pop_back();

    }  

    Symbole * transactionSymbole = new Symbole(ident);   

    //on applique la fonction de transition qui correspond à 
    stateStack.back()->transition(*this,transactionSymbole);
}