/*Créez un programme qui affiche la différence minimum absolue entre deux éléments d’un tableau constitué uniquement de nombres. Nombres négatifs acceptés.


Exemples d’utilisation :
$> python exo.py 5 1 19 21
2


$> python exo.py 20 5 1 19 21
1

$> python exo.py -8 -6 4
2

Afficher error et quitter le programme en cas de problèmes d’arguments.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // Inclure cette bibliothèque pour utiliser INT_MAX

int main(int argc, char const *argv[])
{
    if (argc < 3)  // Vérifie qu'il y a au moins deux arguments
    {
        printf("Veuillez fournir au moins deux nombres en arguments.\n");
        return 1;
    }

    int nombres[argc - 1];
    int minDifference = INT_MAX;  // Initialise la plus petite différence à la valeur maximale possible

    // Conversion des arguments en nombres entiers et stockage dans le tableau
    for (int i = 1; i < argc; i++) 
    {
        nombres[i - 1] = atoi(argv[i]);
    }

    // Calcul de la plus petite différence entre les chiffres du tableau
    for (int i = 0; i < argc - 2; ++i)
    {
        for (int j = i + 1; j < argc - 1; ++j)
        {
            int difference = abs(nombres[i] - nombres[j]);
            if (difference < minDifference)
            {
                minDifference = difference;
            }
        }
    }

    printf("La plus petite différence entre les chiffres est : %d\n", minDifference);

    return 0;
}

//validé