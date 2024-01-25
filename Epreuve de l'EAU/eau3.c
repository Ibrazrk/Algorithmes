/* Créez un programme qui affiche ses arguments reçus à l’envers.


Exemples d’utilisation :
$> python exo.py “Suis” “Je” “Drôle”
Drôle
Je
Suis


$> python exo.py ha ho
ho
ha

$> python exo.py “Bonjour 36”
Bonjour 36

Afficher error et quitter le programme en cas de problèmes d’arguments.
*/

#include <stdio.h>

int main(int argc, char *argv[]) { 

	if (argc < 3) {

        printf("Veuillez fournir au moins 2 arguments.\n");
        return 1;
    }

   
   for (int i = argc-1 ; i > 0; --i) //Pour afficher les arguments sans inclure (null), vous devriez commencer la boucle for à partir de argc - 1 pour accéder au dernier argument et ensuite descendre jusqu'à 0. 
   {
   	
   	printf("%s\n", argv[i]);

   }

    return 0;
}


//validé