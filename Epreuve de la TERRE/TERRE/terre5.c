/*
Créez un programme qui permet de déterminer si l’argument donné est un entier pair ou impair..


Exemples d’utilisation :
$> ruby exo.rb 2
pair

$> ruby exo.rb 5
impair


$> ruby exo.rb Bonjour
Tu ne me la mettras pas à l’envers.

$> ruby exo.rb
Tu ne me la mettras pas à l’envers.


Attention : gérez aussi les entiers négatifs.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])

{
	int nombre = atoi(argv[1]);
   
   if ((nombre%2)==0)
   {

   	printf("pair\n");

   }

   else 

   {
   	printf("impair\n");
   }



	return 0;

}

//Validé//