#ifndef C
#define C
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char chaine[30];
typedef struct personne_bis{
    int age;
    chaine nom;
    struct personne_bis *prec;
    struct personne_bis *suiv;
} Personne_bis;
typedef Personne_bis *Listedc;

Listedc creer_maillon_bis(int, chaine);
void aff_maillon_bis(Listedc);
Listedc saisie_bis(int);
void aff_bis(Listedc);
Listedc detrure_maillon_bis(Listedc);
Listedc detrure_liste_bis(Listedc);
Listedc inserer_tete_bis(Listedc, int, chaine);
Listedc inserer_queue_bis(Listedc, int, chaine);
Listedc inserer_position_bis(Listedc, int, chaine, int);
Listedc supp_tete_bis(Listedc);
Listedc supp_queue_bis(Listedc);
Listedc supp_position_bis(Listedc, int);
int recherche_bis(Listedc, chaine);
Listedc insertion_bis(Listedc, int, chaine, int);
int longueur_liste_bis(Listedc);
#endif