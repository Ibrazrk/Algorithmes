/*Créez un programme qui affiche un rectangle dans le terminal.


Exemples d’utilisation :
$> python exo.py 5 3
o---o
|   |
o---o

$> python exo.py 5 1
o---o

$> python exo.py 1 1
o


Gérer les problèmes potentiels d’arguments.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	//Géstions des erreurs 
	if (!isdigit(argv[1][0]) && !isdigit(argv[2][0]))
    {
    	printf("Veuillez fournir 2 nombres en argument.\n");
        return 1;
    }
	if (argc != 3) {
        printf("Veuillez fournir 2 nombres en argument.\n");
        return 1;
    }

    if (atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0)
    {
    	printf("Veuillez fournir que des nombres superieur à 0 en argument\n");
        return 1;
    }
    
    //Code principale
	int longueur = atoi(argv[1]);
	int largeur = atoi(argv[2]);

	printf("o"); //Toujours afficher un caractere quand longuer=1 et largeur=1

	if (longueur > 1 || largeur > 1) //Condition si la longeur est superieur>1 ou si la largeur>1 
	{
		for (int i = 0; i < longueur-2; ++i)
		{
			printf("-"); // Affichage de tiret entre les caractere 
		}
		printf("o");

	}

	if (largeur > 1) //Condition si la largeur>1
	{	

		for (int i = 0; i < largeur - 2; ++i) //Repeter ce la entre les deux caractere mais de la largeur
		{
			printf("\n"); //Saute une ligne
			printf("|"); //affiche une barre droite
			
			for (int i = 0; i < longueur -2; ++i)
			{	
				printf(" "); //Puis affiche le meme nombre d'espace que de tiret
			}
			printf("|"); //Réaffiche une barre droite
		}
		
		printf("\n");

		//Réafficher la même chose que la premiere ligne
		printf("o");

		for (int i = 0; i < longueur-2; ++i)
		{
			printf("-");
		}
		printf("o");
	}
	printf("\n");
	return 0;
}

//Validé