#ifndef ARBRE 
#define ARBRE
	#include<stdio.h> 
    #include<stdlib.h> 
	#include<limits.h>

	typedef struct noeud{
		int val;
		struct noeud *sag;
		struct noeud *sad;
	} Noeud;
	typedef Noeud *ArbreBinaire;

	ArbreBinaire creer_Noeud(int, ArbreBinaire, ArbreBinaire);
	ArbreBinaire inserer_Noeud_ABR(ArbreBinaire, int);
	void affichePostfixe(ArbreBinaire);
	void afficheInfixe(ArbreBinaire);
	void affichePrefixe(ArbreBinaire);
	int rechercheAB(ArbreBinaire, int);
	int rechercheABR(ArbreBinaire, int);
	int estFeuille(ArbreBinaire);
	int nbFeuilles(ArbreBinaire);
	int nbFeuillesInternes(ArbreBinaire);//le nombre de noeuds qui ne sont pas des feuilles
	int profondeur(ArbreBinaire);
	void affichePrefixeBis(ArbreBinaire a, int depth);
	ArbreBinaire inserer_depth(ArbreBinaire a, int val);
	int maxAB(ArbreBinaire a);
	/* File Arbre */
	typedef struct noeudfile{
		int val;
		ArbreBinaire sag;
		ArbreBinaire sad;
		struct noeudfile *suiv;
	} Noeudfile, *ListeNoeud;

	typedef struct{
		ListeNoeud tete;
		ListeNoeud queue;
		int taille;
	} FileArbre;

	ListeNoeud creer_Noeud_ListeNoeud(int val, ArbreBinaire sag, ArbreBinaire sad);
	FileArbre enfiler(FileArbre f, int val, ArbreBinaire sag, ArbreBinaire sad);
	FileArbre defiler(FileArbre f);
	ListeNoeud tete(FileArbre f);
	FileArbre initFile();
	void parcours(ArbreBinaire a);


#endif

/*
A faire 
inserer en restant equilibré (AB)
inserer en restant equilibré ABR (AVL)
supprimer un noeud ABR
parcours en largeur (utiliser une file)
detruire un arbre

PROPRIETES DE L ARBRE
niveau d'un element

ALGOS USUELS
comparer deux abr
fusionner deux abr
suppression d'une partie d'arbre
*/