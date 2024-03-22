#include "listeschainees.h"
int main(int argc, char* argv[]){
    Liste l = saisieListe(2);
    aff_liste(l);
    l = inserer_tete(l, "tete", 1);
    aff_liste(l);
    l = det_liste(l);
    return 0;
}
