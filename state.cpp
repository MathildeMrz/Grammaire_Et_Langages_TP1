#include <iostream>
#include "state.h"
#include "automate.h"

State::State(string name) : name(name) {};
E0::E0(): State("E0"){}
E1::E1(): State("E1"){}
E2::E2(): State("E2"){}
E3::E3(): State("E3"){}
E4::E4(): State("E4"){}
E5::E5(): State("E5"){}
E6::E6(): State("E6"){}
E7::E7(): State("E7"){}
E8::E8(): State("E8"){}
E9::E9(): State("E9"){}

State::~State(){};

bool E0::transition(Automate & automate, Symbole * s) {
    switch (*s)
    {
        case OPENPAR : 
            automate.decalage(s, new E2);
            break;

        case INT :
            automate.decalage(s, new E3);
            break;
        
        case EXPR : 
             automate.decalage(s, new E1);
            break;
    }
    return false; 
}

bool E1::transition(Automate & automate, Symbole * s) {
    switch (*s)
    {
        case PLUS : 
            automate.decalage(s, new E4);
            break;

        case MULT : 
            automate.decalage(s, new E5);
            break;

        case FIN : 
            return true;//Accepter
    }
    return false; 
}

bool E2::transition(Automate & automate, Symbole * s) {
    switch (*s)
    {
        case INT : 
            automate.decalage(s, new E3);
            break;

        case OPENPAR : 
            automate.decalage(s, new E2);
            break;

        case EXPR : 
            automate.decalage(s, new E6);
            break;
    }
    return false; 
}


bool E3::transition(Automate & automate, Symbole * s) {
    switch (*s)
    {
        case PLUS : 
            //automate.reduction(1,new ExprPlus(s2,s1));
            break;

        case MULT : 
            //automate.reduction(3,new ExprPlus(s2,s1));
            break;

        case CLOSEPAR : 
            //automate.reduction(3,new ExprPlus(s2,s1));
            break;

        case FIN : 
            //automate.reduction(3,new ExprPlus(s2,s1));
            break;
    }
    return false; 
}//TODO

bool E4::transition(Automate & automate, Symbole * s) {
    switch (*s)
    {
        case OPENPAR : 
            automate.decalage(s, new E2);
            break;

        case INT : 
            automate.decalage(s, new E3);
            break;

        case EXPR : 
            automate.decalage(s, new E7);
            break;
    }
    return false; 
}

bool E5::transition(Automate & automate, Symbole * s) {
    switch (*s)
    {
        case OPENPAR : 
            automate.decalage(s, new E2);
            break;

        case INT : 
            automate.decalage(s, new E3);
            break;
        
        case EXPR : 
            automate.decalage(s, new E8);
            break;
    }
    return false; 
}

bool E6::transition(Automate & automate, Symbole * s) {
    switch (*s)
    {
        case PLUS : 
            automate.decalage(s, new E4);
            break;

        case MULT : 
            automate.decalage(s, new E5);
            break;

        case CLOSEPAR : 
            automate.decalage(s, new E9);
            break;
    }
    return false; 
}

bool E7::transition(Automate & automate, Symbole * s) { 
    
    switch (*s)
    {
        case MULT : 
            automate.decalage(s, new E5);
            break;

    }
    return false; 
    
}

bool E8::transition(Automate & automate, Symbole * s) {return false;}
bool E9::transition(Automate & automate, Symbole * s) {return false;}

//à terminer
//OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR 