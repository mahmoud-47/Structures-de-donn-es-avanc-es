#include "arbre.h"

ArbreBinaire creer_Noeud(int age, ArbreBinaire g, ArbreBinaire d){
	ArbreBinaire a = (ArbreBinaire)malloc(sizeof(Noeud));  
	a -> val = age;
	a -> sag = g;
	a -> sad = d;
	return a;
}

//implementer insertion avec l'arbre le moins profond 
ArbreBinaire inserer_depth(ArbreBinaire a, int val){
	if(!a) a = creer_Noeud(val, NULL, NULL);
	else if(profondeur(a->sag)<=profondeur(a->sad))
		a->sag = inserer_depth(a->sag, val);
	else
		a->sad = inserer_depth(a->sad, val);
	return a;
}

ArbreBinaire inserer_Noeud_ABR(ArbreBinaire a, int val){
	if(a == NULL)
		a = creer_Noeud(val, NULL, NULL);
	else{
		if(val <= a->val)
			a->sag = inserer_Noeud_ABR(a->sag, val);
		else
			a->sad = inserer_Noeud_ABR(a->sad, val);
	}
	return a;
}

void affichePostfixe(ArbreBinaire a){
	if(a){
		affichePostfixe(a->sag);
		affichePostfixe(a->sad);
		printf("%d\n", a->val);
	}
}

void afficheInfixe(ArbreBinaire a){
	if(a){
		affichePostfixe(a->sag);
		printf("%d\n", a->val);
		affichePostfixe(a->sad);
	}
}

void affichePrefixe(ArbreBinaire a){
	if(a){
		printf("%d\n", a->val);
		affichePostfixe(a->sag);
		affichePostfixe(a->sad);
	}
}

void affichePrefixeBis(ArbreBinaire a, int depth){
	if(a){
		for(int i=0; i<depth; i++)
			if(i==depth-1)
				printf(" |-");
			else
				printf("   ");
		printf("%d\n", a->val);
		affichePrefixeBis(a->sag, depth+1);
		affichePrefixeBis(a->sad, depth+1);
	}
}

int rechercheAB(ArbreBinaire a, int x){
	if(!a) return 0;
	if(a->val == x) return 1;
	return rechercheAB(a->sag, x) || rechercheAB(a->sad, x);
}

int rechercheABR(ArbreBinaire a, int x){
	if(!a) return 0;
	if(a->val == x) return 1;
	if(x<=a->val)
		return rechercheAB(a->sag, x);
	else
		return rechercheAB(a->sad, x);
}

int maxABR(ArbreBinaire a){
	if(!a) return INT_MIN;
	if(!a->sad) return a->val;
	return maxABR(a->sad);
}

int max(int a, int b){
	return a>b?a:b;
}

int max3(int a, int b, int c){
	int m = a>b?a:b;
	return m>c?m:c;
}

int maxAB(ArbreBinaire a){
	if(a ==  NULL)
		return INT_MIN;
	if(!a->sag && !a->sad)
		return a->val;
	return max3(a->val, maxAB(a->sag) , maxAB(a->sad));
}

int estFeuille(ArbreBinaire a){
	if(!a) return 0;
	if(!a->sag && !a->sad) return 1;
	return 0;
}

int nbFeuilles(ArbreBinaire a){
	if(!a) return 0;
	if(estFeuille(a)) return 1;
	return nbFeuilles(a->sag)+nbFeuilles(a->sad);
}

int nbFeuillesInternes(ArbreBinaire a){
	if(!a) return 0;
	if(estFeuille(a)) return 0;
	return 1+nbFeuillesInternes(a->sag)+nbFeuillesInternes(a->sad);
}

int profondeur(ArbreBinaire a){
	if(!a) return 0;
	return 1 + max(profondeur(a->sag), profondeur(a->sad));
}

/*Listes*/
ListeNoeud creer_Noeud_ListeNoeud(int val, ArbreBinaire sag, ArbreBinaire sad){
	ListeNoeud m = (ListeNoeud)malloc(sizeof(Noeudfile));
	m->val = val;
	m->sad = sad;
	m->sag = sag;
	m->suiv = NULL;
	return m;
}

int fileVide(FileArbre f){
	return f.taille == 0;
}

FileArbre enfiler(FileArbre f, int val, ArbreBinaire sag, ArbreBinaire sad){
	ListeNoeud m = creer_Noeud_ListeNoeud(val, sag, sad);
	if(fileVide(f))
		f.tete = f.queue = m;
	else{
		f.queue->suiv = m;
		f.queue = m;
	}
	f.taille++;
	return f;
}

FileArbre defiler(FileArbre f){
	if(fileVide(f)) return f;
	if(f.taille==1){
		f.taille--;
		free(f.tete);
		f.tete = f.queue = NULL;
		return f;
	}
	ListeNoeud temp = f.tete;
	f.tete = f.tete->suiv;
	free(temp);
	f.taille--;
	return f;
}

ListeNoeud tete(FileArbre f){
	return f.tete;
}

FileArbre initFile(){
	FileArbre f;
	f.tete = f.queue = NULL;
	f.taille = 0;
	return f;
}

void parcours(ArbreBinaire a){
	if(a){
		FileArbre f = initFile();
		f = enfiler(f, a->val, a->sag, a->sad);
		while(!fileVide(f)){
			printf("%d ",tete(f)->val);
			if(tete(f)->sag)
				f = enfiler(f, tete(f)->sag->val, tete(f)->sag->sag, tete(f)->sag->sad);
			if(tete(f)->sad)
				f = enfiler(f, tete(f)->sad->val, tete(f)->sad->sag, tete(f)->sad->sad);
			f = defiler(f);
		}
		printf("\n");
	}
}
