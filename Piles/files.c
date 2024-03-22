#include "files.h"

FilePersonne initFile(){
	FilePersonne f;
	f.taille = 0;
	f.tete = f.queue = NULL;
	return f;
}

int fileVide(FilePersonne f){
	return f.taille==0;
}

Liste tete(FilePersonne f){
	return f.tete;
}

FilePersonne enfiler(FilePersonne f, int a, chaine s){
	if(fileVide(f))
		f.tete = f.queue = inserer_tete(f.tete,s,a);
	else{
		f.queue = inserer_queue(f.queue,s,a);
		f.queue = f.queue->suiv;
	}
	f.taille++;
	return f;
}

FilePersonne defiler(FilePersonne f){
	if(fileVide(f))
		return f;
	f.tete = supp_tete(f.tete);
	if(f.tete==NULL)
		f.queue = NULL;
	f.taille--;
	return f;
}

