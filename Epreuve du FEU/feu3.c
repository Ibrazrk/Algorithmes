/*Créez un programme qui affiche la position de l’élément le plus en haut à gauche (dans l’ordre) d’une forme au sein d’un plateau.


Exemples d’utilisation :
$> cat board.txt
0000
1111
2331
$> cat to_find.txt
11
 1
$> cat unfindable.txt
00
00

$> ruby exo.rb board.txt to_find.txt
Trouvé !
Coordonnées : 2,1
----
--11
---1

$> ruby exo.rb board.txt unfindable.txt
Introuvable

Vous devez gérer les potentiels problèmes d’arguments et de lecture de fichiers.

*/

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    if (argc < 3) {
        printf("Écrire: %s nom_du_fichier1 nom_du_fichier2\n", argv[0]);
        return 1;
    }

    FILE *fichier1;
    FILE *fichier2;
    char ligneboard[100]; // Définir une chaîne de caractères pour stocker la ligne lue pour le board
    char lignefind[100]; // Définir une chaîne de caractères pour stocker la ligne lue pour la recherche
    char board[100][100];
    char to_find[100][100];
    int nombre_lignes_board = 0;
    int nombre_lignes_find = 0;

    fichier1 = fopen(argv[1], "r");
    fichier2 = fopen(argv[2], "r");
    // Vérifier si les fichiers sont ouverts avec succès
    if (fichier1 == NULL || fichier2 == NULL) {
        printf("Impossible d'ouvrir un ou plusieurs fichiers.\n");
        return 1;
    }

    int n = 0;

    while (fgets(ligneboard, sizeof(ligneboard), fichier1) != NULL) {
        strcpy(board[n], ligneboard);
        n++;
        nombre_lignes_board++;
    }

    n = 0; // Réinitialiser n pour la lecture du deuxième fichier

    while (fgets(lignefind, sizeof(lignefind), fichier2) != NULL) {
        strcpy(to_find[n], lignefind);
        n++;
        nombre_lignes_find++;
    }

    printf("Nombre de lignes dans le board: %d\n", nombre_lignes_board);
    printf("Nombre de lignes dans le motif: %d\n", nombre_lignes_find);

    for (int i = 0; i < nombre_lignes_board; ++i) {
        printf("%s", board[i]); // Afficher chaque ligne de board
    }

    printf("\n\n");

    for (int i = 0; i < nombre_lignes_find; ++i) {
        printf("%s", to_find[i]); // Afficher chaque ligne de to_find
    }

    printf("\n\n");
    int found = 0;

    for (int i = 0; i < nombre_lignes_board - nombre_lignes_find + 1; ++i) {
        for (int j = 0; j < strlen(board[i]); ++j) {
            
            
            if (board[i][j] == to_find[0][0]) {
                //printf("Premier trouver \n");
                int k, l;
                found = 1;
                for (k = i; k < i + nombre_lignes_find; ++k) {
                    for (l = j; l < j + strlen(to_find[0]); ++l) {

                        printf("ligne : %d, colonne : %d, board : %c, motif : %c ",k,l,board[k][l], to_find[k - i][l - j]);
                        printf("\n");
                        if (board[k][l] != to_find[k - i][l - j]) {
                            if (to_find[k - i][l - j] == ' ') {

                                break;
                            }
                            found = 0;
                            break; 
                        }
                    }
                    if (!found) {
                        break;
                    }
                }
                if(found) {
                    printf("Trouvé à partir de : colonne %d, ligne %d\n", j , i);
                    return 1;
                } 
            }
        }


    }
    
    if (found == 0) {
       printf("Introuvable\n");
    }

    // Fermer les fichiers
    fclose(fichier1);
    fclose(fichier2);

    return 0;
}

//Validé