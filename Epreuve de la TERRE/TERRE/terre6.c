/*
Créez un programme qui affiche le résultat et le reste d’une division entre deux nombres.


Exemples d’utilisation :
$> python exo.py 5 2
résultat: 2
reste: 1


$> python exo.py 10 0
erreur.


$> python exo.py 3 5
erreur.

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])

{
	int n1 = atoi(argv[1]);
	int n2 = atoi(argv[2]);
	int resultat = (n1)/(n2);
	int reste = resultat % 2;
	
	if (resultat>0)
	{
		printf("Le resultat est : %d\n", resultat);
		printf("Le reste est : %d\n", reste);
	}
	
	else 

	{
		printf("erreur.\n");
	}

	return 0;
}

//Validé//

