/*Créez un programme qui affiche le premier nombre premier supérieur au nombre donné en argument.


Exemples d’utilisation :
$> python exo.py 14
17
$>

Afficher -1 si le paramètre est négatif ou mauvais.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[])

	{

	int arg = atoi(argv[1]);

	if (argc > 2 || ) {

        printf("-1\n");
        return 1;
    }
	

	while (1){

		int n = 0;

		for (int i = 1; i <= arg; ++i)

		{
			double reste = fmod (arg, i);

			if (reste==0.0)
			{
			n++;
			}

		}

		if (n==2)
		{
			printf("%d est le prochain nombre premier aprés ce chiffre\n", arg );
			break;

		}

		else

		{
			arg++;

		}

	}

	return 0;
}

//Validé