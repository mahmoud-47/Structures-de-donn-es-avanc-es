#ifndef FILES
#define FILES
	#include "listeschainees.h"

	//file
	typedef struct{
		int taille;
		Liste tete, queue;
	} FilePersonne;

	FilePersonne initFile();
	int fileVide(FilePersonne);
	Liste tete(FilePersonne);//display only
	FilePersonne enfiler(FilePersonne, int, chaine);
	FilePersonne defiler(FilePersonne);
#endif