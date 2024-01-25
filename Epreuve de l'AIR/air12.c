/*Afficher un escalier constitué d’un caractère et d’un nombre d’étages donné en paramètre.


Exemples d’utilisation :
$> ruby exo.rb O 5
    O
   OOO
  OOOOO
 OOOOOOO
OOOOOOOOO


Afficher error et quitter le programme en cas de problèmes d’arguments.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char const *argv[])
{	
	//Géstion des erreurs

    if (argc != 3) {
        printf("veuillez fournir que 2 arguments\n");
        return 1;
    }
    
    if (isalpha(argv[2][0])&&isdigit(argv[1][0]))
    {
        printf("Veuillez rentrer un caractere comme premier argument et un nombre comme deuxieme argument\n");
        return 1;
    }   
    
	int nombre = atoi(argv[2]);
	const char *arg1 = argv[1];
    char caractere = arg1[0];
	int n = nombre - 1;
	int p = 1;
	for (int i = 0; i < nombre; ++i)
	{
		for (int i = 0; i < n; ++i)
		{
			printf(" ");
		}
		for (int j = 0; j < p; ++j)
		{
			printf("%c",caractere);
		}
		for (int k = 0; k < n; ++k)
		{
			printf(" ");
		}
		printf("\n");
		n = n-1;
		p = p+2;
	}
	return 0;
}

//Validé
