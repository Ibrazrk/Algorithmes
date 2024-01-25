/*Créez un programme qui remplace les caractères vides par des caractères plein pour représenter le plus grand carré possible sur un plateau. Le plateau sera transmis dans un fichier. La première ligne du fichier contient les informations pour lire la carte : nombre de lignes du plateau, caractères pour “vide”, “obstacle” et “plein”.


Exemples d’utilisation :
$> cat plateau
9.xo
...........................
....x......................
............x..............
...........................
....x......................
...............x...........
...........................
......x..............x.....
..x.......x................
$> ruby exo.rb plateau
.....ooooooo...............
....xooooooo...............
.....ooooooox..............
.....ooooooo...............
....xooooooo...............
.....ooooooo...x...........
.....ooooooo...............
......x..............x.....
..x.......x................

Vous devez gérer les potentiels problèmes d’arguments, de fichiers, ou de carte invalide.

Une carte est valide uniquement si : les lignes ont toute la même longueur, il y a au moins une ligne d’une case, les lignes sont séparées d’un retour à la ligne, les caractères présents dans la carte sont uniquement ceux de la première ligne

En cas de plusieurs solutions, le carré le plus en haut à gauche sera choisi.

Vous trouverez un générateur de plateau sur la feuille suivante.*/

#include <stdio.h>
#include <string.h>

// Déclaration de la fonction de recherche de carré
void rechercheCarreDansBoucle(char plateau[100][100], int TAILLE_MAX, int premieri, int premierj, int *dernierx, int *derniery, int *taillecarré, int *premi, int *premj) {
    int carré = 1; // Initialisation de la taille du carré
    int x = 0;
    while (carré <= TAILLE_MAX) {

        for (int i = premieri; i < carré + premieri; ++i) {
            for (int j = premierj; j < carré + premierj; ++j) {

                if (!(plateau[i][j] == '.')) {

                    if (carré > *taillecarré) {
                        *taillecarré = carré;
                        *premi = premieri;
                        *premj = premierj;
                        *dernierx = carré  + premieri - 2 ;
                        *derniery = carré + premierj - 2;
                    }
                    goto fin; // Sortir de la boucle et continuer à la fin du code
                }
            }
        }

        x++; // Augmenter la taille du carré pour la prochaine itération
        carré++;
    }

fin: // Marqueur pour indiquer la fin de la boucle
    return;
}

int main(int argc, char const *argv[]) {
    // gestion des erreurs
    if (argc < 2) {
        printf("Écrire: %s nom_du_fichier\n", argv[0]);
        return 1;
    }

    FILE *fichier;
    char ligne[100];
    char plateau[100][100]; // +1 pour le caractère de fin de chaîne '\0'

    fichier = fopen(argv[1], "r");

    // gestion des erreurs

    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return 1;
    }

    int n = 0;

    while (fgets(ligne, sizeof(ligne), fichier) != NULL && n < 100) {
        ligne[strcspn(ligne, "\n")] = '\0'; // Supprimer le retour à la ligne s'il existe
        strncpy(plateau[n], ligne, 100);    // Copier la ligne
        plateau[n][100] = '\0';              // Assurer que la chaîne soit terminée par un caractère nul
        n++;
    }

    printf("\nPlateau :\n\n");
    for (int i = 0; i < n; ++i) {
        printf("%s\n", plateau[i]); // Afficher chaque ligne de la grille
    }
    printf("\n");

    int TAILLE_MAX = 1000; // Taille maximale souhaitée pour le carré
    int taillecarré = 0;   // Initialisation de la dernière taille de carré complète
    int premi = 0;
    int premj = 0;
    int dernierx = 0;
    int derniery = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 50; ++j) {
            rechercheCarreDansBoucle(plateau, TAILLE_MAX, i, j, &dernierx, &derniery, &taillecarré, &premi, &premj);
        }
    }
    printf("\n\npremi = %d dernierx = %d premj = %d derniery = %d taillecarré = %d\n", premi, dernierx, premj, derniery, taillecarré - 1);
    printf("\nPlateau avec carré :\n\n");

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10000; ++j) {

            if (plateau[i][j] == '\0') {
                break;
            }

            if (i >= premi && i <= dernierx && j >= premj && j <= derniery) {
                printf("O");
            } else {
                printf("%c", plateau[i][j]); // Afficher chaque caractère du plateau
            }
        }
        printf("\n");
    }

    

    return 0;
}

//Validé
