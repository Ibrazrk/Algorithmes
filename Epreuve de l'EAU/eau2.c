/* Créez un programme qui affiche toutes les différentes combinaisons de deux nombre entre 00 et 99 dans l’ordre croissant.


Exemples d’utilisation :
$> python exo.py
00 01, 00 02, 00 03, 00 04, ... , 00 99, 01 02, ... , 97 99, 98 99
$>
*/

#include <stdio.h>

int main() {
    int tab1[100];
    int tab2[100];

    for (int i = 0; i < 100; ++i) {
        tab1[i] = i + 1; // Stocke les chiffres de 1 à 100 dans le tableau
    }
    for (int i = 0; i < 100; ++i) {
        tab2[i] = i + 1; // Stocke les chiffres de 1 à 100 dans le tableau
    }

   
    for (int i = 0; i < 99; ++i) {
        
        for (int j = i+1; j < 99; ++j) {
            
             printf("%02d %02d,", tab1[i], tab2[j]);
                
            
        }
    }

    printf ("\n");

    return 0;
}

//Validé

