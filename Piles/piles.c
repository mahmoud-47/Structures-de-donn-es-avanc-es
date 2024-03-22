#include "piles.h"

PilePersonne initPile(){
	PilePersonne p;
	p.taille = 0;
	p.sommet = NULL;
	return p;
}

int pileVide(PilePersonne p){
	return p.taille==0;
}

Liste sommet(PilePersonne p){
	return p.sommet;
}

PilePersonne empiler(PilePersonne p, int a, chaine s){
	p.sommet = inserer_tete(p.sommet,s,a);
	p.taille++;
	return p;
}

PilePersonne desempiler(PilePersonne p){
	if(pileVide(p)) return p;
	p.sommet = supp_tete(p.sommet);
	p.taille--;
	return p;
}

PilePersonne tfp(FilePersonne f){
	PilePersonne p = initPile();
	Liste l;
	while(!fileVide(f)){
		l = tete(f);
		p = empiler(p,l->age,l->nom);
		f = defiler(f);
	}
	return p;
}

FilePersonne tpf(PilePersonne p){
	FilePersonne f = initFile();
	Liste l;
	while(!pileVide(p)){
		l = sommet(p);
		f = enfiler(f,l->age,l->nom);
		p = desempiler(p);
	}
	return f;
}

PilePersonne fpp(PilePersonne p){
	PilePersonne p2 = initPile();
	Liste l;
	while(!pileVide(p)){
		l = sommet(p);
		p2 = empiler(p2,l->age,l->nom);
		p = desempiler(p);
	}
	return p2;
}