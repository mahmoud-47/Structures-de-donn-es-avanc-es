#include "listeschainees.h" 

Liste creer_maillon(chaine s, int a){
    Liste maillon;
    maillon = (Liste)malloc(sizeof(Personne));
    strcpy(maillon -> nom, s);
    maillon -> age = a;
    maillon -> suiv = NULL;
    return maillon;
}

void aff_maillon(Liste l){
    printf("Nom : %s Age : %d\n", l->nom, l->age);
}

Liste saisieListe(int n){
    Liste l=NULL, m, c;
    if(n>0){
        chaine nom; int age;
        printf("Nom ? "); scanf("%s",nom);
        printf("Age ? "); scanf("%d",&age);
        m = creer_maillon(nom, age);
        l = c = m;
        for(int i=1; i<n; i++){
            printf("Nom ? "); scanf("%s",nom);
            printf("Age ? "); scanf("%d",&age);
            m = creer_maillon(nom, age);
            c -> suiv = m;
            c = m;
        }
    }
    return l;
}

void aff_liste(Liste l){
    Liste c = l;
    while(c){
        aff_maillon(c);
        c = c->suiv;
    }
}

Liste det_maillon(Liste l){
    free(l);
    return NULL;
}

Liste det_liste(Liste l){
    Liste c = l;
    while(l){
        l = l -> suiv;
        free(c);
        c = l;
    }
    return l;
}

Liste inserer_tete(Liste l, chaine s, int n){
    Liste maillon = creer_maillon(s,n);
    maillon -> suiv = l;
    return maillon;
}