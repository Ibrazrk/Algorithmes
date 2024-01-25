/*Créez un programme qui affiche le premier index d’un élément recherché dans un tableau. Le tableau est constitué de tous les arguments sauf le dernier. L’élément recherché est le dernier argument. Afficher -1 si l’élément n’est pas trouvé.


Exemples d’utilisation :
$> python exo.py Ceci est le monde qui contient Charlie un homme sympa Charlie
6


$> python exo.py test test test
0

$> python exo.py test boom
-1

Afficher error et quitter le programme en cas de problèmes d’arguments.
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    if (argc < 2) 
    {
        printf("Veuillez fournir des mots en arguments.\n");
        return 1;
    }

    // Déclaration d'un tableau de pointeurs vers des chaînes de caractères
    const char *mots[argc - 2];

    // Copier les mots depuis les arguments dans le tableau
    for (int i = 1; i < argc; i++) 
    {
        mots[i - 1] = argv[i];
    }

    const char *motRecherche = argv[argc - 1]; // Le mot à rechercher

    for (int i = 0; i < argc - 2; i++) 
    {
        if (strcmp(mots[i], motRecherche) == 0)
        {
            printf("Le mot recherché se trouve à l'index %d.\n", i);
            return 0;
        }
    }

    printf("-1\n");
    return 1;
}

//Validé
