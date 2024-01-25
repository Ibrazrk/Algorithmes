/*Créez un programme qui affiche l’alphabet à partir de la lettre donnée en argument en lettres minuscules suivi d’un retour à la ligne.


Exemples d’utilisation :
$> python exo.py n
nopqrstuvwxyz
$>


Attention : votre programme devra utiliser une boucle.*/


#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	char tab[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char lettre = argv[1][0];
	int entier = lettre-'a';

		for (int i = entier; i <=25; ++i)
		{
			printf ("%c",tab[i]);


		}	
	printf( "\n");
	
	return 0;
}

//validé//