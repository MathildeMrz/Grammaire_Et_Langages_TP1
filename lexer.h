#pragma once

#include <string>
#include "symbole.h"
using namespace std;

class Lexer {

   public:
      Lexer(string s) : flux(s), tete(0), tampon(nullptr) {  cout << "Lexer constructor " << endl; }
      ~Lexer() { }

      Symbole * Consulter();
      void Avancer();

   protected:

      //mot en entrée à analyser
      string flux;

      //indice du symbole analysé dans flux
      int tete;

      //symbole analysé dans le flux
      Symbole * tampon;
};

//décalage (shift ): déplacer la tête de lecture (avancer), empiler (etat cible qu'on trouve derrière le "d" de la table d'analyse) et empiler (symbole lu)
//réduction : on est en train de valider une règle : dépiler n (dépend de la règle. ex : E->val n=1 E->E+E n=3 E->(E) n=3) symboles ("r" avec numéro derrière qui correspond au numéro de la règle)
              //, calculer (au sens faire une nouvelle instance) le symbole de la partie gauche (toujours E). On a fait la partie spécifique à la réduction. 
              //Ensuite, il faut dépiler n états et appeler la transition qui correspond au nouvel état au sommet de la pile

//Attention aux dépendances circulaires entre Automate et Etat => déclaration anticipée avec déclaration de classe vide.

//State.h
//class Automate; (on ne le fait que d'un côté)

//Etat.cpp => 1 classe pour cercle gauche
//Pareil pour symbole

//Transition (arg : ref& vers automate, ptr Symbole (prochain symbole sur la tête de lecture))
//Les 2 piles de symbole et d'état sont toujours de même taille

//soit on veut évaluer l'expression au fur et à mesure ou on veut construire une représentation en mémoire de notre expression (arbre) au quel cas il faut peut être intégrer une autre structure