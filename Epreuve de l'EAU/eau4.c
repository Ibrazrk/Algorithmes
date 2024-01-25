/* Créez un programme qui affiche le N-ème élément de la célèbre suite de Fibonacci. (0, 1, 1, 2) étant le début de la suite et le premier élément étant à l’index 0.


Exemples d’utilisation :
$> python exo.py 3
2
$>

Afficher -1 si le paramètre est négatif ou mauvais.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) { 

	long long int n=100, terme1 = 0, terme2 = 1, termeSuivant;
	long long int tab[n] , arg = atoll(argv[1]);

	if (arg > 100 || argc > 2 ) {

        printf("-1\n");
        return 1;
    }


    for (int i = 0; i < n; ++i) {
        
        if (i <= 1) {

            termeSuivant = i;

        } else {
            termeSuivant = terme1 + terme2;
            terme1 = terme2;
            terme2 = termeSuivant;
        }

        tab[i] = termeSuivant; // stock chaque élément de la suite dans un tableau
      
    }

    printf("%lld\n",tab[arg] );


    return 0;
}

//Validé
