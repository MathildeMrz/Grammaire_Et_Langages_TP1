#pragma once

#include <string>
#include "symbole.h"

using namespace std;

class Automate;

class State {
    public:
        State(string name);
        virtual ~State();
        void print() const;
        virtual bool transition(Automate & automate,Symbole * s) = 0;
        
    protected:
        string name;
};

class E0 : public State 
{
    public :      
        E0();   
        bool transition(Automate & automate, Symbole * s);     
};

class E1 : public State 
{
    public : 
        E1();   
        bool transition(Automate & automate, Symbole * s);     
};

class E2 : public State 
{
    public : 
        E2();   
        bool transition(Automate & automate, Symbole * s);     
};

class E3 : public State 
{
    public : 
        E3();  
        bool transition(Automate & automate, Symbole * s);     
};

class E4 : public State 
{
    public : 
        E4();  
        bool transition(Automate & automate, Symbole * s);     
};

class E5 : public State 
{
    public : 
        E5();  
        bool transition(Automate & automate, Symbole * s);     
};

class E6 : public State 
{
    public : 
        E6();  
        bool transition(Automate & automate, Symbole * s);     
};

class E7 : public State 
{
    public : 
        E7();  
        bool transition(Automate & automate, Symbole * s);     
};

class E8 : public State 
{
    public : 
        E8();  
        bool transition(Automate & automate, Symbole * s);     
};

class E9 : public State 
{
    public : 
        E9();  
        bool transition(Automate & automate, Symbole * s);     
};