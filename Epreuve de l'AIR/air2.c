/*Créez un programme qui découpe une chaîne de caractères en tableau en fonction du séparateur donné en 2e argument.

Votre programme devra intégrer une fonction prototypée comme ceci :
ma_fonction(string_à_couper, string_séparateur) { // syntaxe selon votre langage
	# votre algorithme
	return (tableau)
}


Exemples d’utilisation :
$> python exo.py “Crevette magique dans la mer des étoiles” “la”
Crevette magique dans 
 mer des étoiles

Afficher error et quitter le programme en cas de problèmes d’arguments.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fonctioncut(const char *argument, const char **mots, char separateur) 
{
    int i = 0;

    char *copieArgument = strdup(argument); // Duplication de l'argument pour éviter la modification

    char *token = strtok(copieArgument, " "); // Utilisation de l'espace comme délimiteur

    while (token != NULL)

     {
        if (*token == separateur) 
        {
            mots[i++] = "\n";
        } 

        else 
        {
            mots[i++] = strdup(token); // Copie du mot dans une nouvelle mémoire allouée
        }
        token = strtok(NULL, " ");
    }
    mots[i] = NULL; // Marquage de la fin du tableau avec NULL

    free(copieArgument); // Libération de la mémoire allouée pour la copie de l'argument
}

int main(int argc, char const *argv[]) 
{
    if (argc < 3) { // Vérification des arguments
        printf("Veuillez fournir des mots en argument et un séparateur.\n");
        return 1;
    }

    char cuter = *argv[2];

    const char *mots[100]; // Tableau pour stocker les mots, capacité maximale de 100 mots

    fonctioncut(argv[1], mots, cuter); // Appel de la fonction pour stocker les mots

    // Affichage des mots stockés dans le tableau
    printf("Mots stockés dans le tableau :\n");
    
    for (int i = 0; mots[i] != NULL; ++i) 
    {
        printf("%s ", mots[i]);
    }
    printf("\n");

    // Libération de la mémoire allouée pour les mots
    for (int i = 0; mots[i] != NULL; ++i) 
    {
        if (strcmp(mots[i], "\n") != 0) 
        {
            free((void *)mots[i]);
        }
    }

    return 0;
}

//Validé