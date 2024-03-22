#include "arbre.h"

ArbreNaire creer_Noeud(int age){
	ArbreNaire a = (ArbreNaire)malloc(sizeof(Noeud));  
	a -> age = age;
	a -> frere = NULL;
	a -> enfant = NULL;
}

ArbreNaire saisi