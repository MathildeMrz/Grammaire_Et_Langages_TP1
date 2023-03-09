#pragma once

#include <string>
#include "symbole.h"
using namespace std;

class Lexer {

   public:
      Lexer(string s) : flux(s), tete(0), tampon(nullptr) { }
      ~Lexer();
      Symbole * Consulter();
      void Avancer();
      void saveReductionSymbol(Symbole *s);
      string getFlux(){ return flux ;}
      void setFlux(string flux);
      void resetLexer(string flux);


   protected:
      string flux;
      int tete;
      Symbole * tampon;
};