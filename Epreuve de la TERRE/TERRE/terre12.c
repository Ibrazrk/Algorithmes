/*Créez un programme qui transforme une heure affichée en format 24h en une heure affichée en format 12h.


Exemples d’utilisation :
$> ruby exo.rb 23:40
11:40PM

Attention : midi et minuit.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("erreur\n");
        return 1;
    }

    char *heureComplete = argv[1];
    char *minuteStr = strchr(heureComplete, ':'); // Recherche le premier deux-points

    if (minuteStr == NULL) {
        printf("erreur\n");
        return 1;
    }

    *minuteStr = '\0'; // Remplace ':' par '\0' pour diviser la chaîne en heures et minutes
    int heure = atoi(heureComplete); // Convertit la partie heures en entier
    int minute = atoi(minuteStr + 1); // Convertit la partie minutes après ':'

    if (heure > 12)
    {
    	heure = heure - 12;
    	printf("%02d:%02dPM\n", heure, minute);
    }

    else

    {
    	printf("%02d:%02dAM\n", heure, minute);
    }

    

    return 0;
}

//Validé