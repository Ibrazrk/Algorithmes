/*Créez un programme qui détermine si une chaîne de caractère se trouve dans une autre.


Exemples d’utilisation :
$> python exo.py bonjour jour
true


$> python exo.py bonjour joure
false


$> python exo.py 42
error

Afficher error et quitter le programme en cas de problèmes d’arguments.
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    const char *mot1 = argv[1];
    const char *mot2 = argv[2];
    int last_position = 0; // La dernière position trouvée.
    int n = 0;

    for (int i = 0; mot2[i] != '\0'; ++i)
    {
        int found = 0; // Variable pour vérifier si un caractère a été trouvé.
        for (int j = last_position; mot1[j] != '\0'; ++j)
        {
            if (mot1[j] == mot2[i])
            {
                last_position = j;
                found = 1;
                n++;
                break; // Sortez de la boucle interne si une correspondance est trouvée.
            }
        }
        if (!found) {
            printf("False\n");
            return 0; // Sortir du programme si un caractère de mot2 n'a pas été trouvé.
        }
    }

    if (n == strlen(mot2))
   {
        printf("True\n");
   }
   else
   {
        printf("False\n");
   }

    return 0;
}

//validé





