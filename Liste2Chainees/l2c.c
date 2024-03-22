#include "l2c.h"

Listedc creer_maillon_bis(int a, chaine s){
    Listedc m = (Listedc)malloc(sizeof(Personne_bis));
    m -> age = a;
    strcpy(m -> nom, s);
    m -> suiv = m -> prec = NULL;
    return m; 
}

void aff_maillon_bis(Listedc m){
    printf("Nom : %s, Age : %d\n", m -> nom, m -> age);
}

Listedc saisie_bis(int n){
    Listedc l,c,m; int i, a;
    chaine s;
    if(n>0){
        printf("Donner le nom et l'âge ");
        scanf("%s %d", s, &a);
        m = creer_maillon_bis(a, s);
        l = c = m;
        for(i = 1; i < n; i++){
            printf("Donner le nom et l'âge ");
            scanf("%s %d", s, &a);
            m = creer_maillon_bis(a, s);
            c -> suiv = m;
            m -> prec = c;
            c = m;
        }
        return l;
    }else return NULL;
}
void aff_bis(Listedc l){
    Listedc c, p;
    c = l;
    while(c -> suiv){
        aff_maillon_bis(c);
        c = c -> suiv;
    }
    aff_maillon_bis(c); // it doesn't display the last node
    p = c;
    while(p){
        aff_maillon_bis(p);
        p = p -> prec;
    }
}
Listedc detrure_maillon_bis(Listedc m){
    free(m);
    return NULL;
}
Listedc detrure_liste_bis(Listedc l){
    Listedc c = l;
    while(l){
        l = l -> suiv;
        c = detrure_maillon_bis(c);
        c = l;
    }
    return NULL;
}

Listedc inserer_tete_bis(Listedc l, int a, chaine s){
    Listedc m = creer_maillon_bis(a, s);
    if(l == NULL) return m;
    m -> suiv = l;
    l -> prec = m;
    return m;
}

Listedc inserer_queue_bis(Listedc l, int a, chaine s){
    Listedc m = creer_maillon_bis(a, s);
    if(l == NULL)
        l = m;
    else{
        Listedc c = l;
        while(c -> suiv)
            c = c -> suiv;
        c -> suiv = m;
        m -> prec = c;
    }
    return l;
}
Listedc inserer_position_bis(Listedc l, int a, chaine s, int pos){
    Listedc c = l, t, m; int i;
    //verifier que la position est entre 0 et le nombre de maillons -1 
    m = creer_maillon_bis(a, s);
    if(l == NULL)
        l = m;
    else{
        for(i = 1; i < pos; i++)
            c = c -> suiv;
        t = c -> suiv;
        m -> suiv = t;
        m -> prec = c;
        c -> suiv = m;
        t -> prec = m;
    }
    return l;
}
Listedc supp_tete_bis(Listedc l){
    Listedc c = l;
    if(l != NULL){
        l = l -> suiv;
        c = detrure_maillon_bis(c);
    }
    return l;
}
Listedc supp_queue_bis(Listedc l){
    Listedc c = l; 
    if(l == NULL) return NULL;
    while(c -> suiv)
        c = c -> suiv;
    c -> prec -> suiv = NULL;
    c = detrure_maillon_bis(c);
    return l;
}
Listedc supp_position_bis(Listedc, int);
int recherche_bis(Listedc, chaine);