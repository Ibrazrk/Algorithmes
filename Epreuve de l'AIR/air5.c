/*Créez un programme qui affiche une chaîne de caractères en évitant les caractères identiques adjacents.


Exemples d’utilisation :
$> python exo.py “Hello milady,   bien ou quoi ??”
Helo milady, bien ou quoi ?


Afficher error et quitter le programme en cas de problèmes d’arguments.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("Veuillez fournir une chaîne de caractères en argument.\n");
        return 1;
    }

    const char *chaine = argv[1]; // Récupère la chaîne de caractères passée en argument
    int taille = strlen(chaine);

    // Alloue un tableau pour stocker les caractères de la chaîne
    char *caracteres = (char *)malloc(taille * sizeof(char));

    // Vérifie si l'allocation a réussi
    if (caracteres == NULL) {
        printf("Allocation de mémoire a échoué.\n");
        return 1;
    }

    // Copie caractère de la chaîne dans le tableau
    for (int i = 0; i < taille; i++) {
        caracteres[i] = chaine[i];
    }

    // Affichage des caractères stockés dans le tableau
    printf("Caractères stockés dans le tableau : ");
    for (int i = 0; i < taille; i++) {
    	if (caracteres[i]!= caracteres[i+1])
    	{
    		printf("%c", caracteres[i]);
    	}
    }
    printf("\n");

    // Libération de la mémoire allouée pour le tableau
    free(caracteres);

    return 0;
}

//Validé