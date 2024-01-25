/*Créez un programme qui affiche si un nombre est premier ou pas.

Exemples d’utilisation :
$> node exo.js 5
Oui, 5 est un nombre premier.

$> node exo.js 6
Non, 6 n’est pas un nombre premier.

Attention : 0 et 1 ne sont pas des nombres premiers. Gérez les erreurs d’arguments.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])

{
	int n1 = atoi(argv[1]); 
	int n = 0;


	for (int i = 1; i <= n1; ++i)
	{
		double reste = fmod(n1, i);

		if (reste==0.0)
		{
			n++;
		}

	}

		if (n==2)
		{
			printf("Oui,%d est un nombre premier\n", n1 );

		}

		else

		{
			printf("Non,%d n'est pas un nombre premier\n", n1 );
		}
	
	
	return 0;
}

//Validé


