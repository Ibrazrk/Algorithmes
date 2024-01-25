/*Code avec la logique du BFS*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int x;
    int y;
} Point;

void afficherLabyrintheNumerote(int numerotation[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (numerotation[i][j] == -1) {
                printf("   ");
            } else {
                printf("%2d ", numerotation[i][j]);
            }
        }
        printf("\n");
    }
}

void afficherChemin(char labyrinthe[MAX_ROWS][MAX_COLS], Point chemin[], int longueur) {
    for (int i = 0; i < longueur; ++i) {

        // Ne mettez 'o' que si la case n'est ni '1' ni '2' ni 'o'
        if (labyrinthe[chemin[i].y][chemin[i].x] != '1' && labyrinthe[chemin[i].y][chemin[i].x] != '2' && labyrinthe[chemin[i].y][chemin[i].x] != 'o') {
            labyrinthe[chemin[i].y][chemin[i].x] = 'o';
        }
    }

    printf("Nombre de coups : %d\n", longueur-2);
}



void trouverCheminPlusCourt(char labyrinthe[MAX_ROWS][MAX_COLS], int rows, int cols, Point sortie, Point *entree, Point chemin[]) {
    int numerotation[MAX_ROWS][MAX_COLS];

    // Initialiser toutes les cases avec -1 (non visité)
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            numerotation[i][j] = -1;
        }
    }

    // La sortie a une distance de 0
    numerotation[sortie.y][sortie.x] = 0;

    // Liste des directions possibles (haut, bas, gauche, droite)
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Utiliser une file d'attente pour gérer les cases à explorer
    int fileAttente[MAX_ROWS * MAX_COLS * 2];  // Tableau pour la file d'attente (x, y, x, y, ...)
    int debutFile = 0, finFile = 0;

    // Ajouter la sortie à la file d'attente
    fileAttente[finFile++] = sortie.x;
    fileAttente[finFile++] = sortie.y;

    // Parcourir la file d'attente
    while (debutFile < finFile) {
        // Retirer les coordonnées d'une case de la file d'attente
        int x = fileAttente[debutFile++];
        int y = fileAttente[debutFile++];

        // Vérifier les cases voisines
        for (int d = 0; d < 4; ++d) {
            int ni = y + directions[d][0];
            int nj = x + directions[d][1];

            // Vérifier si la case voisine est à l'intérieur du labyrinthe, non visitée et sans obstacle
            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && numerotation[ni][nj] == -1 && labyrinthe[ni][nj] != '*') {
                // Numéroter la case voisine
                numerotation[ni][nj] = numerotation[y][x] + 1;

                // Ajouter la case voisine à la file d'attente
                fileAttente[finFile++] = nj;
                fileAttente[finFile++] = ni;
            }
        }
    }

    // Afficher le labyrinthe numerote
    /*printf("Labyrinthe numerote :\n");
    afficherLabyrintheNumerote(numerotation, rows, cols);*/

    // Retrouver le chemin à partir de l'entrée
    int longueurChemin = numerotation[entree->y][entree->x] + 1;
    Point position = *entree;

    for (int i = longueurChemin - 1; i >= 0; --i) {
        chemin[i] = position;

        // Trouver la case voisine avec un numéro inférieur
        for (int d = 0; d < 4; ++d) {
            int ni = position.y + directions[d][0];
            int nj = position.x + directions[d][1];

            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && numerotation[ni][nj] == i) {
                position.x = nj;
                position.y = ni;
                break;
            }
        }
    }

    // Afficher le chemin dans le labyrinthe
    afficherChemin(labyrinthe, chemin, longueurChemin);
}
int main(int argc, char const *argv[]) {
    // Gestion des erreurs pour s'assurer que le nom du fichier est fourni en argument
    if (argc < 2) {
        printf("Écrire: %s nom_du_fichier\n", argv[0]);
        return 1;
    }

    FILE *fichier;
    char ligne[MAX_COLS];
    char labyrinthe[MAX_ROWS][MAX_COLS];

    fichier = fopen(argv[1], "r");

    // Gestion des erreurs pour s'assurer que le fichier est ouvert avec succès
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return 1;
    }

    int n = 0;
    int colonnes = 0;

    // Lire le labyrinthe depuis le fichier
    while (fgets(ligne, sizeof(ligne), fichier) != NULL && n < MAX_ROWS) {
        ligne[strcspn(ligne, "\n")] = '\0'; // Supprimer le retour à la ligne s'il existe
        strncpy(labyrinthe[n], ligne, MAX_COLS - 1);
        labyrinthe[n][MAX_COLS - 1] = '\0';
        n++;

        // Mettre à jour le nombre maximal de colonnes rencontrées
        int longueurLigne = strlen(ligne);
        if (longueurLigne > colonnes) {
            colonnes = longueurLigne;
        }
    }

    fclose(fichier);

    // Déterminer les coordonnées de l'entrée (S) et de la sortie (E)
    Point entree, sortie;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            if (labyrinthe[i][j] == '1') {
                entree.x = j;
                entree.y = i;
            } else if (labyrinthe[i][j] == '2') {
                sortie.x = j;
                sortie.y = i;
            }
        }
    }

    // Afficher le labyrinthe pour débogage
    printf("Labyrinthe lu depuis le fichier :\n\n");
    for (int i = 0; i < n; ++i) {
        printf("%s\n", labyrinthe[i]);
    }

    // Afficher des messages de débogage
    /*printf("Coordonnées de l'entrée : (%d, %d)\n", entree.x, entree.y);
    printf("Coordonnées de la sortie : (%d, %d)\n", sortie.x, sortie.y);*/

    // Trouver le chemin le plus court et l'afficher
    Point chemin[MAX_ROWS * MAX_COLS];
    trouverCheminPlusCourt(labyrinthe, n, colonnes, sortie, &entree, chemin);

    // Afficher le labyrinthe après la recherche du chemin
    printf("\nLabyrinthe avec chemin :\n\n");
    for (int i = 0; i < n; ++i) {
        printf("%s\n", labyrinthe[i]);
    }

    return 0;
}