/*Créez un programme qui trie une liste de nombres. Votre programme devra implémenter l’algorithme du tri par sélection.

Vous utiliserez une fonction de cette forme (selon votre langage) :
my_select_sort(array) {
	# votre algorithme
	return (new_array)
}


Exemples d’utilisation :
$> python exo.py 6 5 4 3 2 1
1 2 3 4 5 6


$> python exo.py test test test
error

Afficher error et quitter le programme en cas de problèmes d’arguments.


Wikipedia vous présentera une belle description de cet algorithme de tri.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  

// Fonction pour trier un tableau d'entiers en utilisant le tri par séléction
void my_sort(int tableau[], int taille) {

    // Tri à bulles (bubble sort) pour permuter les éléments dans l'ordre croissant
    for (int i = 0; i < taille - 2; i++) 
    {

    	int min = i;

        // Trouver l'index du minimum dans la partie non triée du tableau
        for (int j = i + 1; j < taille; j++) 
        {
            if (tableau[j] < tableau[min]) 
            {
                min = j;
            }
        }

        // Permuter les éléments
        int temp = tableau[i];
        tableau[i] = tableau[min];
        tableau[min] = temp;

    }

}

// Fonction principale
int main(int argc, char const *argv[]) 
{
    //Géstion des erreurs
    if (argc < 3) 
    {
        printf("Veuillez fournir au moins 2 nombres en argument.\n");
        return 1;
    }

    for (int i = 1; i < argc; ++i)
    {   
        for (int j = 0; argv[i][j] != '\0'; ++j)
        {
            if (isalpha(argv[i][j]))
            {
            printf("Veuillez rentrer que des nombres\n");
            return 1;
            }
        }
    }

    // Déclaration d'un tableau de nombres de longueur argc-1 qui est le nombre d'arguments
    int nombres[argc - 1];

    // Remplir le tableau avec des valeurs à partir des arguments en ligne de commande
    for (int i = 1; i < argc; i++)  
    {
        nombres[i - 1] = atoi(argv[i]);
    }
     
    // Appeler la fonction de tri
    my_sort(nombres, argc);

    // Afficher le tableau trié
    printf("Tableau trié : ");
    for (int m = 0; m < argc-1 ; m++) 
    {
        printf("%d ", nombres[m]);
    }
    printf("\n");

    return 0;
}

//Validé
