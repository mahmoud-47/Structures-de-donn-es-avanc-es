#ifndef ARBRE 
#define ARBRE
	#include<stdio.h> 
    #include<stdlib.h>
	typedef struct noeud{
		int age;
		struct noeud *frere;
		struct noeud *enfant;
	} Noeud;
	typedef Noeud *ArbreNaire;

	ArbreNaire creer_Noeud(int);
#endif