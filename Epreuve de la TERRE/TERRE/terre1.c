/*Epreuve de la terre Exercice 1

Consigne : Créez un programme qui affiche l’alphabet en lettres minuscules suivi d’un retour à la ligne.

Exemples d’utilisation :
$> python exo.py
abcghidefjklmnopqrstuvwxyz
$>

Attention : votre programme devra utiliser une boucle.*/


#include <stdio.h>


int main()
{
	char tab[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

	
	
		for (int i = 0; i <=25; ++i)
		{
			printf ("%c",tab[i]);


		}	
	printf( "\n");
	
	return 0;
}


//Validé//