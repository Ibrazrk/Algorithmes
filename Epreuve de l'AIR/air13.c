/*Créez un programme qui trie une liste de nombres. Votre programme devra implémenter l’algorithme du tri rapide (QuickSort).

Vous utiliserez une fonction de cette forme (selon votre langage) :
my_quick_sort(array) {
	# votre algorithme
	return (new_array)
}


Exemples d’utilisation :
$> python exo.py 6 5 4 3 2 1
1 2 3 4 5 6



Afficher error et quitter le programme en cas de problèmes d’arguments.


Wikipedia vous présentera une belle description de cet algorithme de tri.
*/

/*partitionner(tableau T, entier premier, entier dernier, entier pivot)
    échanger T[pivot] et T[dernier]  // échange le pivot avec le dernier du tableau , le pivot devient le dernier du tableau
    j := premier
    pour i de premier à dernier - 1 // la boucle se termine quand i = (dernier élément du tableau).
        si T[i] <= T[dernier] alors
            échanger T[i] et T[j]
            j := j + 1
    échanger T[dernier] et T[j]
    renvoyer j

tri_rapide(tableau T, entier premier, entier dernier)
        si premier < dernier alors
            pivot := choix_pivot(T, premier, dernier)
            pivot := partitionner(T, premier, dernier, pivot)
            tri_rapide(T, premier, pivot-1)
            tri_rapide(T, pivot+1, dernier)*/

#include <stdio.h>
#include <stdlib.h>

void tri_rapide(int tableau[], int debut, int fin) {
    if (debut < fin) {
        int pivot = debut;
        int i = debut + 1;
        int j = fin;

        while (i <= j) {
            if (tableau[i] <= tableau[pivot]) {
                i++;
            } else if (tableau[j] >= tableau[pivot]) {
                j--;
            } else {
                int temp = tableau[i];
                tableau[i] = tableau[j];
                tableau[j] = temp;
                i++;
                j--;
            }
        }

        int temp = tableau[pivot];
        tableau[pivot] = tableau[j];
        tableau[j] = temp;

        tri_rapide(tableau, debut, j - 1);
        tri_rapide(tableau, j + 1, fin);
    }
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("Veuillez fournir au moins un nombre en argument.\n");
        return 1;
    }

    int taille = argc - 1;
    int tab[taille]; // Taille du tableau

    for (int i = 1; i < argc; i++) {
        tab[i - 1] = atoi(argv[i]);
    }

    tri_rapide(tab, 0, taille - 1);

    for (int i = 0; i < taille; ++i) {
        printf("%d\n", tab[i]);
    }

    return 0;
}

//Validé
