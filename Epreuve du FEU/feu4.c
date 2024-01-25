/*Créez un programme qui trouve et affiche la solution d’un Sudoku.


Exemples d’utilisation :
$> cat s.txt
1957842..
3.6529147
4721.3985
637852419
8596.1732
214397658
92.418576
5.8976321
7612358.4

$> ruby exo.rb s.txt
195784263
386529147
472163985
637852419
859641732
214397658
923418576
548976321
761235894

Afficher error et quitter le programme en cas de problèmes d’arguments.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h> // Inclure ctype.h pour utiliser isdigit()

#define TAILLE_GRILLE 9

bool chiffrevalide(char chiffre, int ligne, int colonne, char const sudoku[TAILLE_GRILLE][TAILLE_GRILLE + 1])
{

    // Recherche d'un chiffre dans ligne et colonne

    for (int i = 0; i < TAILLE_GRILLE; ++i) 
    {
        if (sudoku[i][colonne] == chiffre || sudoku[ligne][i] == chiffre) 
        {
            return false;
        }
    }
    // Recherche dans carré
    int debutligne = (ligne / 3) * 3;
    int finligne = debutligne + 3;
    int debutcolonne = (colonne / 3) * 3;
    int fincolonne = debutcolonne + 3;

    for (int i = debutligne; i < finligne; ++i)
    {
        for (int j = debutcolonne; j < fincolonne; ++j)
        {
            if (sudoku[i][j] == chiffre)
            {
                return false;
            }
        }
    }

    return true;
}

bool resolutionsudoku(char sudoku[TAILLE_GRILLE][TAILLE_GRILLE + 1])
{
    int colonne = -1, ligne = -1; 
    bool casevide = false;

    for (int i = 0; i < TAILLE_GRILLE; ++i)
    {
        for (int j = 0; j < TAILLE_GRILLE; ++j)
        {
            if (sudoku[i][j] == '.')
            {
                ligne = i;
                colonne = j;
                casevide = true; //indique que la case est bien vide
                break;
            }
        }

        if (casevide) // si elle est vide alors passer au suivant
        {
            break;
        }
    }
    if (!casevide) { // S'il n'y a pas de case vide, la grille est résolue
        return true;
    }

    for (char chiffre = '1'; chiffre <= '9'; ++chiffre)
    {
        if (chiffrevalide(chiffre, ligne, colonne, sudoku))
        {
            sudoku[ligne][colonne] = chiffre;

            // Récursion pour résoudre le reste de la grille
            if (resolutionsudoku(sudoku))
            {
                return true;
            }

            // Si la solution n'est pas trouvée, remettre la case à '.' et essayer un autre chiffre
            sudoku[ligne][colonne] = '.';
        }
    }

    return false; // Aucune solution trouvée pour cette configuration
}

int main(int argc, char const *argv[])
{
    //gestion des erreurs
    if (argc < 2) {
        printf("Écrire: %s nom_du_fichier\n", argv[0]);
        return 1;
    }

    FILE *fichier;
    char ligne[100];
    char sudoku[TAILLE_GRILLE][TAILLE_GRILLE+1]; // +1 pour le caractère de fin de chaîne '\0'

    fichier = fopen(argv[1], "r");

    //gestion des erreurs

    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier.\n");
        return 1;
    }

    int n = 0;

    while (fgets(ligne, sizeof(ligne), fichier) != NULL && n < TAILLE_GRILLE) {
        ligne[strcspn(ligne, "\n")] = '\0'; // Supprimer le retour à la ligne s'il existe
        strncpy(sudoku[n], ligne, TAILLE_GRILLE); // Copier la ligne
        sudoku[n][TAILLE_GRILLE] = '\0'; // Assurer que la chaîne soit terminée par un caractère nul
        n++;
    }
    
    printf("\nGrille de Sudoku :\n\n");
    for (int i = 0; i < n; ++i) {
        printf("%s\n", sudoku[i]); // Afficher chaque ligne de la grille
    }
    //Géstion des erreurs si ce n'est pas des chiffres ou des "."
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
        {
            if (!(isdigit(sudoku[i][j])||sudoku[i][j]== '.'))
            {
                printf("Le sudoku doit etre composé que de '.' ou de chiffre\nLe sudoku doit etre composé de 9 lignes et 9 colonnes\n");
                return 1;
            }
        }
    }
    printf("\n");
    
    if (resolutionsudoku(sudoku))
    {
        // Afficher la grille de sudoku modifiée
        printf("\nGrille de Sudoku modifiée :\n\n");
        for (int i = 0; i < TAILLE_GRILLE; ++i) 
        {
            printf("%s\n", sudoku[i]);
        }
    }
    
    fclose(fichier);

    return 0;
}

//Validé
