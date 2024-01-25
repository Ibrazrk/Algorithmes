/*Créez un programme qui fusionne deux listes d’entiers triées en les gardant triées, les deux listes seront séparées par un “fusion”.

Utilisez une fonction de ce genre (selon votre langage) :
sorted_fusion(array1, array2) {
	# your algo
	return (new_array)
}


Exemples d’utilisation :
$> ruby exo.rb 10 20 30 fusion 15 25 35
10 15 20 25 30 35


Afficher error et quitter le programme en cas de problèmes d’arguments.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

void fusion(int tableau1[], int tableau2[], int taille1, int taille2, int tab[]) {
    
    int n = 0;

    for (int i = 0; i < taille1; ++i) {
        
        if (tableau1[i] > tableau2[i]) {
             
                tab[n] = tableau2[i];
                tab[n+1] = tableau1[i];
		}
		else {
				tab[n] = tableau1[i];
                tab[n+1] = tableau2[i];
		}

		n=n+2;
    }

    
}

int main(int argc, char const *argv[]) {
	//Géstion des erreurs

    if (argc < 8) {
        printf("Veuillez fournir au moins un nombre 6 arguments.\n");
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

    int tab1[100];
    int tab2[100];
    int n = -1;
    int nb1 = 0;
    int nb2 = 0;

    for (int i = 1; i < argc; ++i) {
        tab1[nb1++] = atoi(argv[i]); // Ajout de valeurs dans tab1

        if (strcmp(argv[i], "fusion") == 0) { // Vérification si l'argument est "fusion"
            n = nb1; // Conserve la position pour scinder tab1
        }
    }

    int tab[nb1 + nb2]; // Taille du tableau final
    
    if (n != -1 && n < nb1) { // Vérifie si "fusion" a été trouvé et n'est pas à la dernière position
        for (int i = n; i < nb1; ++i) {
            tab2[nb2++] = tab1[i]; // Copie des valeurs de tab1 à partir de la position n vers tab2
        }
        nb1 = n - 1; // Redimensionne tab1 à partir de la position n
    }

    fusion(tab1, tab2, nb1, nb2, tab);

    printf("tab :\n");
    for (int j = 0; j < nb1 + nb2; ++j) {
        printf("%d\n", tab[j]);
    }

    return 0;
}

//Validé
