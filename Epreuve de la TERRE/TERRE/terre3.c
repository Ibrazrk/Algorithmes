/*Créez un programme qui affiche les arguments qu’il reçoit ligne par ligne, peu importe le nombre d’arguments.


Exemples d’utilisation :
$> ruby exo.rb je suis solide !
je
suis
solide
!*/

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        for (int i = 1; i < argc; ++i)
        {
            printf("%s\n", argv[i]);
        }
        
    } else {
        printf("pas d'argument\n");
    }

    return 0;
}

//Validé//