/*Créez un programme qui affiche toutes les valeurs comprises entre deux nombres dans l’ordre croissant. Min inclus, max exclus.


Exemples d’utilisation :
$> python exo.py 20 25
20 21 22 23 24


$> python exo.py 25 20
20 21 22 23 24

$> python exo.py hello
error

Afficher error et quitter le programme en cas de problèmes d’arguments.
*/


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	if (argc < 3) 
    {

        printf("Error\n");
        return 1;
    }

	int nb1 = atoi(argv[1]);
	int nb2 = atoi(argv[2]);

	if (nb1<nb2)
	{
		for (int i = 0; i < nb2-nb1; ++i)
		{
			
			int nb= nb1+i;
			printf("%d ",nb);
		}
	}

	if (nb2<nb1)
	{
		for (int i = 0; i < nb1-nb2; ++i)
		{
			
			int nb= nb2+i;
			printf("%d ",nb);
		}
	}

	printf ("\n");

	return 0;
}

//Validé