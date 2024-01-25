/*Créez un programme qui transforme une heure affichée en format 12h en une heure affichée au format 24h.


Exemples d’utilisation :
$> ruby exo.rb 11:40PM
23:40

Attention : midi et minuit.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) { 
	
    if (argc < 2) {

        printf("Veuillez fournir une heure au format HH:MM en argument.\n");
        return 1;
    }

    char *heureComplete = argv[1];
    char *minuteStr = strchr(heureComplete, ':'); // Recherche le premier deux-points
	char *pm = strchr(heureComplete, 'P');

    


    if (minuteStr == NULL) {
        printf("Format d'heure invalide. Utilisez le format HH:MM.\n");
        return 1;
    }

    *minuteStr = '\0'; // Remplace ':' par '\0' pour diviser la chaîne en heures et minutes
    
    int heure = atoi(heureComplete); // Convertit la partie heures en entier
    int minute = atoi(minuteStr + 1); // Convertit la partie minutes après ':'

    

    if (pm != NULL) {	

       
        heure = heure+12; // Ajouter 12 heures pour PM
    }

    printf("%02d:%02d\n", heure, minute); // Affiche l'heure au format HH:MM*/

    return 0;
}

//Validé

