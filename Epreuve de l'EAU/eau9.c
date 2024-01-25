/*Créez un programme qui détermine si une chaîne de caractères ne contient que des chiffres.


Exemples d’utilisation :
$> python exo.py “4445353”
true


$> python exo.py 42
true

$> python exo.py “Bonjour 36”
false

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

                for (int k = 0; k < 26; ++k) // Parcourt les lettres minuscules
                { 
                    if (caractere == tabmin[k] || caractere == tabmaj[k]) // Si le caractère correspond à une lettre minuscule ou majuscule
                    { 
                        printf("false\n");
                        return 1; // Sort du programme
                    }

                }
        }
   
    }

    printf("true\n");
    return 0;
}

//Validé