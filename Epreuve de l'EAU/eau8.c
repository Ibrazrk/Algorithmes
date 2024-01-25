/*Créez un programme qui met en majuscule la première lettre de chaque mot d’une chaîne de caractères. Les autres lettres devront être en minuscules. Les mots ne sont délimités que par un espace, une tabulation ou un retour à la ligne.

Exemples d’utilisation :
$> python exo.py “bonjour mathilde, comment vas-tu ?!”
Bonjour Mathilde, Comment Vas-tu ?!


$> python exo.py 42
error

Afficher error et quitter le programme en cas de problèmes d’arguments.
*/

#include <stdio.h>

int main(int argc, char const *argv[]) 
{
    char tabmin[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char tabmaj[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    if (argc < 2) 
    {

        printf("Error\n");
        return 1;
    }

    for (int i = 1; i < argc; ++i) // Parcourt les mots passés en argument (argv[1], argv[2], ...)
    { 
        const char *mot = argv[i]; // Récupère le mot à traiter

        for (int j = 0; mot[j] != '\0'; ++j) // Parcourt chaque caractère du mot


        { 
            char caractere = mot[j]; // Stocke le caractère actuel dans 'caractere'

            if (j == 0) // Si l'indice du caractère est le premier
            { 
                for (int k = 0; k < 26; ++k) // Parcourt les lettres minuscules
                { 
                    if (caractere == tabmin[k]) // Si le caractère correspond à une lettre minuscule
                    { 
                        caractere = tabmaj[k]; // Change la casse en majuscule
                        break; // Sort du boucle
                    }
                }
            } 
            else // Si l'indice du caractère n'est pas le premier
            { 
                for (int k = 0; k < 26; ++k) // Parcourt les lettres majuscules
                { 
                    if (caractere == tabmaj[k]) // Si le caractère correspond à une lettre majuscule
                    { 
                        caractere = tabmin[k]; // Change la casse en minuscule
                        break; // Sort de la boucle
                    }
                }
            }
            
            printf("%c", caractere); 

        }
    printf(" ");
    }

    printf("\n"); // Passe à la ligne après avoir traité tous les mots
    return 0;
}

//Validé