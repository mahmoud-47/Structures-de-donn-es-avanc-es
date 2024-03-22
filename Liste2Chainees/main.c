#include "l2c.h"

Listedc l = NULL;

int main(){
    l = saisie_bis(3);
    inserer_position_bis(l,6,"tuuu",1);
    aff_bis(l);
    return 0;
}