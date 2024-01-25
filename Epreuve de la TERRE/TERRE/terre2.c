/*Créez un programme qui affiche son nom de fichier.


Exemples d’utilisation :
$> node exo.js
exo.js

$> node crevette.js
crevette.js */

#include <stdio.h>
#include <libgen.h>

int main(int argc, char *argv[]) {
    if (argc > 0) {
        char *programName = basename(argv[0]);
        printf("Le nom du programme est : %s\n", programName);
    } else {
        printf("Impossible de déterminer le nom du programme.\n");
    }

    return 0;
}

//Validé//