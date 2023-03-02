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
        void decalage(Symbole * s, State * e);
        void reduction(int n,Symbole * s);
        bool analyse();
        
    private :
        vector <State*> stateStack;
        vector <Symbole*> symbolStack;
        Lexer* lexer;
};