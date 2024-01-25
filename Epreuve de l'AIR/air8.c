/*Créez un programme qui ajoute à une liste d’entiers triée un nouvel entier tout en gardant la liste triée dans l’ordre croissant. Le dernier argument est l’élément à ajouter.

Utilisez une fonction de ce genre (selon votre langage) :
sorted_insert(array, new_element) {
	# your algo
	return (new_array)
}


Exemples d’utilisation :
$> ruby exo.rb 1 3 4 2
1 2 3 4

$> ruby exo.rb 10 20 30 40 50 60 70 90 33
10 20 30 33 40 50 60 70 90


Afficher error et quitter le programme en cas de problèmes d’arguments.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void fonction(int tab[], int nombre, int taille) {
    int n = -1; // Déclaration de 'n' en dehors de la boucle pour la rendre visible après la boucle

    for (int i = 0; i < taille; ++i) {
        if (tab[i] > nombre || tab[i] == 0) { // Vérifie également les valeurs nulles (non définies)
            n = i;
            break;
        }
    }

    for (int j = taille; j > n; --j) {
        tab[j] = tab[j - 1];
    }

    tab[n] = nombre;
}

int main(int argc, char const *argv[]) {
    
    //Géstion des erreurs

    if (argc < 4) {
        printf("Veuillez fournir au moins un nombre 3 arguments.\n");
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

    //Code principale

    int nombre = atoi(argv[argc - 1]);
    int taille = argc - 2; // La taille du tableau sera le nombre d'arguments moins le dernier et le premier argument

    int tab[taille + 1]; // Augmentation de la taille du tableau pour inclure le nombre à insérer

    for (int i = 1; i < argc - 1; i++) {
        tab[i - 1] = atoi(argv[i]);
    }

    fonction(tab, nombre, taille + 1); // Augmentation de la taille passée à la fonction

    for (int i = 0; i < taille + 1; ++i) {
        printf("%d\n", tab[i]);
    }

    return 0;
}

//Validé
