/*

Créez un programme qui affiche l’inverse de la chaîne de caractères donnée en argument.


Exemples d’utilisation :
$> node exo.js “Hello world!”
!dlrow olleH


$> node exo.js “lehciM”
Michel

Attention : je compte sur vous pour gérer les potentielles erreurs d’arguments.

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{ 

for (int n = argc-1 ; n >= 1 ; n--)

    

{
 	char mot[100]; // Définissez ici la taille maximale du mot que vous souhaitez traiter
 	char lettres[100]; // Tableau pour stocker les lettres extraites
 	int len;
    strcpy(mot, argv[n]);
    int cs = 0;

	
	len = strlen(mot); //stock le longueur du mot dans len


    int j = 0;

    for (int i = 0; i < len; i++) {
        if (isalpha(mot[i])) {
            lettres[j] = mot[i];
            j++;
        }
        else{
            cs = 1;
        }
    }

lettres[j] = '\0'; // Ajout d'un caractère nul pour former une chaîne de caractères valide.
    if (cs )
    {
        printf("Erreur\nNe pas mettre de caracteres speciaux");
        break;
    }

    else{
    

    for (int k = j-1; k >=0; --k)
    {

    	printf ("%c",lettres[k]);


    }
    }

    printf (" ");
}


	printf ("\n");

    return 0;

}