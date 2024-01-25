/*Créez un programme qui découpe une chaîne de caractères en tableau (séparateurs : espaces, tabulations, retours à la ligne).

Votre programme devra utiliser une fonction prototypée comme ceci :
ma_fonction(string_à_couper, string_séparateur) { // syntaxe selon votre langage
	# votre algorithme
	return (tableau)
}


Exemples d’utilisation :
$> python exo.py “Bonjour les gars”
Bonjour
les
gars

Afficher error et quitter le programme en cas de problèmes d’arguments.
*/

#include <stdio.h>
//Fonction pour separer des chaines de caracteres dans un tableau
void separateur (const char *tableau[],const char *arg[], int taille) 
{

  for (int i = 1; i < taille; i++) 
    {
        tableau[i - 1] = arg[i];
    }
}

int main(int argc, char const *argv[])
{
	//Géstion des erreurs
    if (argc < 3) 
    {
        printf("Veuillez fournir au moins 2 caracteres en argument.\n");
        return 1;
    }
	// Déclaration d'un tableau de chaînes de caractères
	const char *mots[argc - 1];
	// Appeler la fonction separateur
	separateur(mots,argv,argc);

	for (int m = 0; m < argc-1; m++) 
    {
        printf("%s ", mots[m]);printf("\n");
    }
    

    return 0;
}

//Validé


