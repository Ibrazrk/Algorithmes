/*Créez un programme qui trouve le plus court chemin entre l’entrée et la sortie d’un labyrinthe en évitant les obstacles.


Le labyrinthe est transmis en argument du programme. La première ligne du labyrinthe contient les informations pour lire la carte : LIGNESxCOLS, caractère plein, vide, chemin, entrée et sortie du labyrinthe. 


Le but du programme est de remplacer les caractères “vide” par des caractères “chemin” pour représenter le plus court chemin pour traverser le labyrinthe. Un déplacement ne peut se faire que vers le haut, le bas, la droite ou la gauche.

Exemples d’utilisation :
$> cat -e example.map
10x10* o12$
*****2****$
* *   ****$
*   **** *$
* ****   *$
*  *     2$
*  ** *  *$
*     * **$
***  **  *$
1     ****$
**********$

$> ruby exo.rb example.map
10x10* o12
*****2****
* *   **** 
*   **** *
* ****   * 
*  * oooo2
*  **o*  *
*  ooo* **
***o **  *
1ooo  ****
**********
=> SORTIE ATTEINTE EN 12 COUPS !


Vous devez gérer les erreurs / Vous trouverez un générateur de labyrinthe en annexe de cet exercice.*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool navigation(char plateau[100][100], int *nx, int *ny, int *p)
{
    if (plateau[*ny][*nx + 1] == ' ')
    {
        *p = 1;
        return true;
    }
    if (plateau[*ny][*nx - 1] == ' ')
    {
        *p = 2;
        return true;
    }
    if (plateau[*ny + 1][*nx] == ' ')
    {
        *p = 3;
        return true;
    }
    if (plateau[*ny - 1][*nx] == ' ')
    {
        *p = 4;
        return true;
    }

    return false;
}

int main(int argc, char const *argv[])
{
    // gestion des erreurs
    if (argc < 2)
    {
        printf("Écrire: %s nom_du_fichier\n", argv[0]);
        return 1;
    }

    FILE *fichier;
    char ligne[100];
    char plateau[100][100]; //+1 pour le caractère de fin de chaîne '\0'
    char labyrinthe[100][100];

    fichier = fopen(argv[1], "r");

    // gestion des erreurs

    if (fichier == NULL)
    {
        printf("Impossible d'ouvrir le fichier.\n");
        return 1;
    }

    int n = 0;

    while (fgets(ligne, sizeof(ligne), fichier) != NULL && n < 100)
    {
        ligne[strcspn(ligne, "\n")] = '\0'; // Supprimer le retour à la ligne s'il existe
        strncpy(plateau[n], ligne, 100);    // Copier la ligne
        strncpy(labyrinthe[n], ligne, 100);
        plateau[n][99] = '\0';               // Assurer que la chaîne soit terminée par un caractère nul
        labyrinthe[n][99] = '\0';
        n++;
    }

    printf("\nLabyrinthe :\n\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%s\n", labyrinthe[i]); // Afficher chaque ligne de la grille
    }

    int startx = 0;
    int starty = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            if (plateau[i][j] == '1')
            {
                startx = j;
                starty = i;
            }
        }
    }

    printf("startx = %d, starty = %d\n", startx, starty);

    int nx = startx;
    int ny = starty;
    int nres = 0;
    char resolution[100][5];
    int ntest = 0;
    int ntest2 = 0;
    int p = 0;

    while (/*ntest != 45*/ plateau[ny][nx + 1] != '2' && plateau[ny][nx - 1] != '2' && plateau[ny + 1][nx] != '2' && plateau[ny - 1][nx] != '2')
    {
        /*if(ntest2 == 1){
            break4
        }*/
        ntest++;

        if (navigation(plateau, &nx, &ny, &p))
        {
            if (p == 1)
            {
                plateau[ny][nx + 1] = 'o';
                nx = nx + 1;
            }
            else if (p == 2)
            {
                plateau[ny][nx - 1] = 'o';
                nx = nx - 1;
            }
            else if (p == 3)
            {
                plateau[ny + 1][nx] = 'o';
                ny = ny + 1;
            }
            else if (p == 4)
            {
                plateau[ny - 1][nx] = 'o';
                ny = ny - 1;
            }

            resolution[nres][0] = nx;
            resolution[nres][1] = ny;
            nres++;
            continue;
        }
        else
        {
            for (int i = nres - 1 ; i >= 0; --i)
            {
                // printf("x : %d y : %d\n",resolution[i][0],resolution[i][1]-1);
                // printf("%c\n",plateau[resolution[i][1]-1][resolution[i][0]]);
                // printf("nx:%d ny:%d\n",nx, ny);
                
                if (plateau[resolution[i][1]][resolution[i][0] + 1] == ' ' || plateau[resolution[i][1]][resolution[i][0] - 1] == ' ' ||
                    plateau[resolution[i][1] + 1][resolution[i][0]] == ' ' || plateau[resolution[i][1] - 1][resolution[i][0]] == ' ')
                {
                    nres = i;
                    nx = resolution[i][0];
                    ny = resolution[i][1];
                    
                    // printf("OK\n");
                    // ntest2 = 1;
                    break;
                    // for (int i = 0; i < n; ++i)
                    //     {
                    //         printf("%s\n", plateau[i]); // Afficher chaque ligne de la grille
                    //     }

                }

                    plateau[resolution[i][1]][resolution[i][0]] = '*';
                    resolution[i][0] = '\0';
                    resolution[i][1] = '\0';
                    // for (int i = 0; i < n; ++i)
                    //     {
                    //         printf("%s\n", plateau[i]); // Afficher chaque ligne de la grille
                    //     }
                    
                
            }
        }
    }
    // Affichage du labyrinthe résolu
    for (int i = 0; i < nres; ++i)
    {
        labyrinthe[resolution[i][1]][resolution[i][0]] = 'o';
    }

    // Affichage du labyrinthe final
    printf("\nLabyrinthe résolution :\n\n");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            if (labyrinthe[i][j] == '\0')
            {
                break;
            }
            printf("%c", labyrinthe[i][j]); // Afficher chaque ligne de la grille
        }
        printf("\n");
    }


   

   // printf("nres:%d, resolution[i][0]: %d, resolution[i][1]: %d\n", nres, nx, ny);

    printf("\nTableau résolution :\n\n");
    for (int i = 0; i < nres; ++i)
    {
        printf("(%d, %d)\n", resolution[i][0], resolution[i][1]); // Afficher chaque coordonnée
    }

    printf("\n");

    return 0;
}