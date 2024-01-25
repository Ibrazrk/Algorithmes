/*Créez un programme qui affiche le nombre de caractères 
d’une chaîne de caractères passée en argument.*/

#include <stdio.h>
#include <ctype.h> //Pour le traitement de caractères individuels
#include <string.h> //pour le traitement de chaînes de caractères.

int main(int argc, char const *argv[]) {
    
    int longueur = 0; // Initialise la variable "longueur" à 0.

    // Parcours tous les arguments en ligne de commande, à l'exception du premier (nom du programme).
    
    for (int n = 1; n < argc; ++n) {
       
        const char *mot = argv[n]; // Pointe vers la chaîne de caractères actuelle, concatenne les caractere dans un tableau.

        // Parcours chaque caractère de la chaîne jusqu'à la fin (caractère nul).
        
        for (int i = 0; mot[i] != '\0'; ++i) {
            
            longueur++; // Incrémente la longueur à chaque caractère trouvé.
        }
    }

    printf("%d\n", longueur); // Affiche la longueur totale des chaînes.

    return 0;
}
//Validé//