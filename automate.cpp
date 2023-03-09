#include <iostream>
#include "automate.h"

Automate::Automate(string chaine)
{
    this->lexer = new Lexer(chaine);
    E0 * startingState = new E0();
    stateStack.push_back(startingState);
}

Automate::~Automate()
{
    for(int i = 0; i < stateStack.size(); ++i)
    {
        delete this->stateStack.at(i);
    }

    for(int i = 0; i < symbolStack.size(); ++i)
    {
        delete this->symbolStack.at(i);
    }

    delete this->lexer;
}

int Automate::analyse()
{
    bool prochainEtat = false;

    while(!prochainEtat)
    {
        Symbole *s = lexer->Consulter();
        this->lexer->Avancer();
        prochainEtat = stateStack.back()->transition(*this, s);       
    } 
    
    if(*symbolStack.back() == ERREUR)
    {
        cout << "Incorrect syntex, the word doesn't exist" << endl;
        return -1;
    }   
        
    cout << "Correct syntax, the word exists : " << this->lexer->getFlux() << " = " << symbolStack.back()->getValue() << endl;
    return symbolStack.back()->getValue();
}

void Automate::shift(Symbole * s, State * e) 
{     
    symbolStack.push_back(s);
    stateStack.push_back(e);
}

void Automate::reduction(int n, Symbole * s) 
{
    vector <Symbole *> unstackedSymboles;

    for (int i=0;i<n;i++)
    {
        delete(stateStack.back());
        stateStack.pop_back();
        unstackedSymboles.push_back(symbolStack.back());
        symbolStack.pop_back();
    }

    int lastsUnstacked = 0;

    if(n == 1)
    {
        Entier * E = (Entier *) unstackedSymboles.back();
        lastsUnstacked = ((Entier*)E)->getValue();
    }
    else if(n == 3)
    {
        if(*(unstackedSymboles.back()) == OPENPAR)
        {
            delete unstackedSymboles.back();
            unstackedSymboles.pop_back();
            Entier * E = (Entier *) unstackedSymboles.back();
            lastsUnstacked = E->getValue();
            delete E;
        }
        else
        {
            Entier * E = (Entier *) unstackedSymboles.back();
            lastsUnstacked = E->getValue();
            delete unstackedSymboles.back();
            unstackedSymboles.pop_back();

            if(*(unstackedSymboles.back()) == PLUS)
            {
                delete unstackedSymboles.back();
                unstackedSymboles.pop_back();
                Entier * E = (Entier *) unstackedSymboles.back();
                lastsUnstacked = lastsUnstacked + E->getValue();     
                delete E;           
            }
            else//MULT
            {
                delete unstackedSymboles.back();
                unstackedSymboles.pop_back();
                Entier * E = (Entier *) unstackedSymboles.back();
                lastsUnstacked = (lastsUnstacked * E->getValue());  
                delete E;         
            }      
        }
    }
     stateStack.back()->transition(*this,new Expr(lastsUnstacked));
    lexer->saveReductionSymbol(s);
}

void Automate::setFlux(string flux)
{
    this->lexer->setFlux(flux);
}