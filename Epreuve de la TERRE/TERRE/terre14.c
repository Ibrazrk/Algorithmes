/* Créez un programme qui prend en paramètre trois entiers et affiche la valeur du milieu.


Exemples d’utilisation :
$> ruby exo.rb 11 40 34
34

$> ruby exo.rb 2 1 3
2

$> ruby exo.rb 2 2 2
erreur.


Fonctions interdites: 
-La fonction sort */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) { 
    if (argc < 4) {
        printf("Veuillez fournir trois nombres en arguments.\n");
        return 1;
    }

    int nb1 = atoi(argv[1]);
    int nb2 = atoi(argv[2]);
    int nb3 = atoi(argv[3]);

    if ((nb1 > nb2 && nb1 < nb3) || (nb1 < nb2 && nb1 > nb3)) {
        printf("%d\n", nb1);
    }

    if ((nb2 > nb1 && nb2 < nb3) || (nb2 < nb1 && nb2 > nb3)) {
        printf("%d\n", nb2);
    }

    if ((nb3 > nb2 && nb3 < nb1) || (nb3 < nb2 && nb3 > nb1)) {
        printf("%d\n", nb3);
    }

    return 0;
}


//Validé




