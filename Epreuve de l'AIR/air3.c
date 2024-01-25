/*Créez un programme qui transforme un tableau de chaînes de caractères en une seule chaîne de caractères. Espacés d’un séparateur donné en dernier argument au programme.

Utilisez une fonction de ce genre (selon votre langage) :
ma_fonction(array_de_strings, separateur) {
	# votre algorithme
	return (string)
}


Exemples d’utilisation :
$> python exo.py “je” “teste” “des” “trucs” “ “
Je teste des trucs


Afficher error et quitter le programme en cas de problèmes d’arguments.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void concat(const char *tableau[], const char *arg[], char separateur, int taille) {
    for (int i = 1; i < taille; i++) {
        // Allouer dynamiquement de la mémoire pour chaque mot
        char *temp = malloc(strlen(arg[i]) + 2); // +2 pour le separateur et le caractère nul
        strcpy(temp, arg[i]); // Copie de l'argument dans le tableau temporaire
        
        char sep[2];
        sep[0] = separateur;
        sep[1] = '\0';

        strcat(temp, sep); // Concaténation du separateur à la fin du mot

        tableau[i - 1] = temp;
    }
}

int main(int argc, char const *argv[]) {
    // Gestion des erreurs
    if (argc < 3) {
        printf("Veuillez fournir au moins 2 caractères en argument.\n");
        return 1;
    }

    // Déclaration d'un tableau de chaînes de caractères
    const char *mots[argc - 1];
    // Déclaration du separateur
    char separateur = ' '; // Utilisation de char au lieu de char*

    // Appeler la fonction concat
    concat(mots, argv, separateur, argc);

    // Afficher les mots avec espace
    for (int m = 0; m < argc - 1; m++) {
        printf("%s", mots[m]);
        free((void *)mots[m]); // Libérer la mémoire allouée pour chaque mot
    }
    printf("\n");

    return 0;
}
//Validé