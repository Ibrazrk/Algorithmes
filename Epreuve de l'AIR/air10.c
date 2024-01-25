/*Créez un programme qui décale tous les éléments d’un tableau vers la gauche. Le premier élément devient le dernier à chaque rotation.

Utilisez une fonction de ce genre (selon votre langage) :
ma_rotation(array) {
	# votre algorithme
	return (new_array)
}


Exemples d’utilisation :
$> python exo.py “Michel” “Albert” “Thérèse” “Benoit”
Albert, Thérèse, Benoit, Michel


Afficher error et quitter le programme en cas de problèmes d’arguments.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void rotation(char tableau[][100], int taille)
{
	char premier_mot[100]; 
	strcpy(premier_mot, tableau[0]);

	for (int i = 0; i < taille ; ++i)
	{
		strcpy(tableau[i],tableau[i+1]);
		
	}

	strcpy(tableau[taille-1],premier_mot);
}

int main(int argc, char const *argv[])
{
	//Géstion des erreurs

    if (argc < 4) {
        printf("Veuillez fournir au moins 3 arguments.\n");
        return 1;
    }

	char tab[100][100];
	int taille = argc-1;

	for (int i = 1; i < argc; ++i) 
	{
        strcpy(tab[i - 1], argv[i]);
    }

    rotation(tab,taille);

    for (int i = 0; i < taille; ++i)
    {
    	printf("%s\n", tab[i]);
    }
  
	return 0;
}

//Validé