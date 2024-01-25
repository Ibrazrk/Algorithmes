/*Créez un programme qui est capable de reconnaître et de faire une opération (addition ou soustraction) sur chaque entier d’une liste.


Exemples d’utilisation :
$> ruby exo.rb 1 2 3 4 5 “+2”
3 4 5 6 7

$> ruby exo.rb 10 11 12 20 “-5”
5 6 7 15


L’opération à appliquer sera toujours le dernier élément.


Afficher error et quitter le programme en cas de problèmes d’arguments.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char const *argv[])

{
	// Gestion des erreurs
    if (argc < 4) 
    {
        printf("Veuillez fournir au moins 3 arguments.\n");
        return 1;
    }

    for (int i = 1; i < argc; ++i)
    {   
        for (int j = 0; argv[i][j] != '\0'; ++j)
        {
            if (isalpha(argv[i][j]))
            {
            printf("Veuillez rentrer que des nombres\n");
            return 1;
            }
        }
    }

    //Déclaration d'un tableau
	int tab[argc - 1];
	//Remplie le tableau avec les arguments
    for (int i = 1; i < argc ; i++)
    {
        tab[i - 1] = atoi(argv[i]);
    }

    for (int i = 0; i < argc - 2; ++i)
    {
    	int n = tab[i]+tab[argc-2];
    	
    	printf("%d ", n );
    }

    printf("\n");
	return 0;
}