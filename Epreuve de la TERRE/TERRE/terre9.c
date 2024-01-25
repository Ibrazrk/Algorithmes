/*Créez un programme qui affiche le résultat d’une puissance.
L’exposant ne pourra pas être négatif.*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])

{
	int n1 = atoi(argv[1]);
	int n2 = atoi(argv[2]);
	int n = n1*n1;
	
		if (n2>0)
		{
			for (int i = 0; i<(n2-2); ++i)
		{
			
			 n=n*n1;

		}
		printf("resultat=%d\n", n );

		}
		
		else

		{
			printf ("erreur\n");
		}

	return 0;
}


//Validée