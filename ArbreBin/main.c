#include "arbre.h"
int main(int argc, char const *argv[])
{
	int t[10]={4,8,2,5,6,9,7,2,3,4};
	int taille = 10;
	ArbreBinaire a1 = NULL;
	printf("Insertion Binary Search Tree\n");
	for(int i=0; i<taille; i++)
		a1 = inserer_Noeud_ABR(a1, t[i]);
	affichePrefixeBis(a1, 0);
	printf("Insertion En comparant les profondeurs\n");
	ArbreBinaire a2 = NULL;
	for(int i=0; i<taille; i++)
		a2 = inserer_depth(a2, t[i]);
	affichePrefixeBis(a2, 0);
	printf("La profondeur de a2 = %d\n", profondeur(a2));
	printf("Le nombre de feuilles de a2 = %d\n", nbFeuilles(a2));
	printf("Le nombre de feuilles internes de a2 = %d\n", nbFeuillesInternes(a2));
	printf("LA valeur max de a2 = %d\n", maxAB(a2));
	printf("Recherche de 1 dans a2(ABR) : %d\n",rechercheAB(a2, 1));
	printf("Recherche de 2 dans a2(ABR) : %d\n",rechercheAB(a2, 2));
	printf("Recherche de 1 dans a1(BST) : %d\n",rechercheABR(a1, 1));
	printf("Recherche de 2 dans a1(BST) : %d\n",rechercheABR(a1, 2));
	FileArbre f = initFile();
	parcours(a2);
	return 0;
}