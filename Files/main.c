#include "files.h"

int main(int argc, char const *argv[]){
	FilePersonne f = initFile();
	int a; chaine s;
	for(int i=0; i<5; i++){
		printf("age et nom ");
		scanf("%d %s",&a,s);
		f = enfiler(f,a,s);
	}
	while(!fileVide(f)){
		aff_maillon(tete(f));
		f = defiler(f);
	}
	return 0;
}