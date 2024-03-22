#ifndef PILES
#define PILES
	#include "listeschainees.h"
	#include "files.h"

	//file
	typedef struct{
		int taille;
		Liste sommet;
	} PilePersonne;

	PilePersonne initPile();
	int pileVide(PilePersonne);
	Liste sommet(PilePersonne);//display only
	PilePersonne empiler(PilePersonne, int, chaine);
	PilePersonne desempiler(PilePersonne);
	PilePersonne tfp(FilePersonne); //transfert file -> pile
	FilePersonne tpf(PilePersonne);
	PilePersonne fpp(PilePersonne);
#endif