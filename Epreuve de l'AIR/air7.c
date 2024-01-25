/*Créez un programme qui supprime d’un tableau tous les éléments qui ne contiennent pas une autre chaîne de caractères.

Utilisez une fonction de ce genre (selon votre langage) :
ma_fonction(array_de_strings, string) {
	# votre algorithme
	return (nouvel_array_de_strings)
}


Exemples d’utilisation :
$> python exo.py “Michel” “Albert” “Thérèse” “Benoit” “t”
Michel

$> python exo.py “Michel” “Albert” “Thérèse” “Benoit” “a”
Michel, Thérèse, Benoit



Afficher error et quitter le programme en cas de problèmes d’arguments.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void fonction(char tableau[][100], char mot[][100], char lettre, int taille) {
    for (int i = 0; i < taille; ++i) {
        int trouve = 0; // Variable pour vérifier la présence de la lettre
        for (int j = 0; tableau[i][j] != '\0'; ++j) {
            if (tableau[i][j] == lettre || tableau[i][j] == toupper(lettre)) {
                trouve = 1; // Marque le mot si la lettre est trouvée
                break; // Sort de la boucle dès que la lettre est trouvée
            }
        }
        // Si la lettre est trouvée dans le mot, le copier dans le tableau de mots
        if (trouve == 0) {
            strcpy(mot[i], tableau[i]);
        }
    }
}

int main(int argc, char const *argv[]) {
    if (argc < 6) {
        printf("Veuillez fournir au moins 5 arguments.\n");
        return 1;
    }

    char tab[100][100];
    char mot[100][100];
    const char *dernierArg = argv[argc - 1];
    char lettre = dernierArg[0];
    int taille = argc - 1;

    for (int i = 1; i < argc; ++i) {
        strcpy(tab[i - 1], argv[i]);
    }

    fonction(tab, mot, lettre, taille);

    for (int i = 0; i < taille; ++i) {
        if (mot[i][0] != '\0') { // Vérifie si le mot n'est pas vide avant de l'afficher
            printf("%s\n", mot[i]);
        }
    }
    

    return 0;
}

//Validé
