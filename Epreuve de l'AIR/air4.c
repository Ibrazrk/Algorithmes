/*Créez un programme qui retourne la valeur d’une liste qui n’a pas de paire.


Exemples d’utilisation :
$> python exo.py 1 2 3 4 5 4 3 2 1
5

$> python exo.py bonjour monsieur bonjour
monsieur


Afficher error et quitter le programme en cas de problèmes d’arguments.
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) 
{
	// Gestion des erreurs
    if (argc < 4) 
    {
        printf("Veuillez fournir au moins 3 arguments.\n");
        return 1;
    }
    const char *tab[argc - 1];
    //Remplie le tableau avec les arguments
    for (int i = 1; i < argc; i++)
    {
        tab[i - 1] = argv[i];
    }
    //Deux boucle for pour comparer chaque argument avec les autres
    for (int i = 0; i < argc - 1; ++i) 
    {
        int n = 0; //Variable qui sert de drapeau

        for (int j = 0; j < argc - 1; ++j) 
        {
            if (i != j && strcmp(tab[i], tab[j]) == 0)  //Condition si i et j son different et que tab[i]=tab[j]
            {

                n = 1; //Le drapeau est activé lorsque il trouve un doublon
                break;
            }
        }

        if (n == 0) //Si le drapeau n'est pas activé c'est qu'il le caractere n'a pas de doublon
        { 
            printf("%s\n", tab[i]);
        }
    }

    return 0;
}

//Validé

