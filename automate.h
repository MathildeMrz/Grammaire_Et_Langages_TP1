#pragma once

#include <string>
#include <vector>

#include "symbole.h"
#include "state.h"
#include "lexer.h"

using namespace std;

class Automate {

    public :     
        Automate(string chaine);
        ~Automate(); 
        void shift(Symbole * s, State * e);
        void reduction(int n,Symbole * s);
        void setFlux(string flux);
        int analyse();
        void reset(string chaine);
        
    private :
        vector <State*> stateStack;
        vector <Symbole*> symbolStack;
        Lexer* lexer;
};