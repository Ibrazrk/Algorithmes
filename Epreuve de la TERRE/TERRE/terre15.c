/* Créez un programme qui détermine si une liste d’entiers est triée ou pas.


Exemples d’utilisation :
$> ruby exo.rb 9 8 3
Pas triée !

$> ruby exo.rb 3 8 9 12
Triée !

$> ruby exo.rb “Salut”
erreur.


Fonctions interdites: 
-La fonction sort

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) { 
    if (argc < 4 ) {

        printf("Veuillez fournir trois nombres en arguments.\n");
        return 1;
    }

    int nb1 = atoi(argv[1]);
    int nb2 = atoi(argv[2]);
    int nb3 = atoi(argv[3]);

    if (nb1 < nb2 && nb2 < nb3)  {
        printf("Triée !\n");
    }

    else{
    	printf("Pas triée !\n");
    }

    return 0;
}
