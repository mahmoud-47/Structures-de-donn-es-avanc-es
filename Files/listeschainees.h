#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

typedef char chaine[30];
typedef struct personne{
    chaine nom;
    int age;
    struct personne *suiv;
} Personne;
typedef Personne* Liste;

Liste creer_maillon(chaine, int);
void aff_maillon(Liste);
Liste saisieListe(int);
void aff_liste(Liste);
Liste det_maillon(Liste);
Liste det_liste(Liste);
Liste inserer_tete(Liste, chaine, int);
Liste inserer_queue(Liste, chaine, int);
Liste supp_tete(Liste l);
Liste supp_queue(Liste l);