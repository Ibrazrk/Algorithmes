/*Créez un programme qui affiche le contenu d’un fichier donné en argument.


Exemples d’utilisation :
$> cat a.txt
Je danse le mia
$> ruby exo.rb “a.txt”
Je danse le mia


Afficher error et quitter le programme en cas de problèmes d’arguments ou de fichier inaccessible.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fichier;
    char caractere;
    char nom_fichier[100];
    strcpy(nom_fichier,argv[1]);

    fichier = fopen(nom_fichier, "r"); // Ouvrir le fichier en mode lecture ("r")

    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return 1;
    }

    // Lire et afficher chaque caractère du fichier
    while ((caractere = fgetc(fichier)) != EOF) {
        printf("%c", caractere);
    }

    fclose(fichier); // Fermer le fichier après avoir terminé la lecture

	
	return 0;
}

//Validé