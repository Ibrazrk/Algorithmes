/*Créez un programme qui affiche la racine carrée d’un entier positif.


Exemples d’utilisation :
$> node exo.js 9
3

Attention : je compte sur vous pour gérer les potentielles erreurs d’arguments.


Fonctions interdites: 
-La fonction sqrt*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])

{
	int n1 = atoi(argv[1]); 

	double exposant = 0.5;

	double resultat = pow (n1, exposant);
	
	printf("resultat = %f\n",resultat);
	
	return 0;
}

//Validé