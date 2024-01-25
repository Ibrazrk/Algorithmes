/*Créez un programme qui trie les éléments donnés en argument par ordre ASCII.


Exemples d’utilisation :
$> python exo.py Alfred Momo Gilbert
Alfred Gilbert Momo


$> python exo.py A Z E R T Y
A E R T Y Z

Afficher error et quitter le programme en cas de problèmes d’arguments.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction pour trier un tableau de chaînes de caractères en utilisant le tri à bulles
void my_sort(const char *tableau[], int taille) 
{
    // Tri à bulles pour permuter les éléments dans l'ordre ASCII avec la fonction strcmp
    for (int j = 0; j < taille - 1; j++) 
    {
        for (int k = 0; k < taille - 1 - j; k++) 
        {
            if (strcmp(tableau[k], tableau[k + 1]) > 0) 
            {
                // Permutation des éléments
                const char *temp = tableau[k];
                tableau[k] = tableau[k + 1];
                tableau[k + 1] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[]) 
{
    // Déclaration d'un tableau de chaînes de caractères
    const char *mots[argc - 1];

    // Copier les mots depuis les arguments dans le tableau
    for (int i = 1; i < argc; i++) 
    {
        mots[i - 1] = argv[i];
    }

    // Appeler la fonction de tri
    my_sort(mots, argc - 1);

    // Afficher le tableau trié
    printf("Tableau trié : ");
    for (int m = 0; m < argc - 1; m++) 
    {
        printf("%s ", mots[m]);
    }
    printf("\n");

    return 0;
}

//Validé