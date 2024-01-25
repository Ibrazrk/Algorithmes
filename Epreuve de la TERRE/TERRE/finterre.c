#include <stdio.h>

int main () {
	
	char reponse;
	
	printf("As-tu terminer l'épreuve de la terre ?\n Tape o pour oui ou tape n pour non\n");
	scanf ("%s", &reponse);

	if (reponse == 'o' )
	{
		printf("Bravo\n");
	}

	else{

		printf("Travail encore\n");
	}


	return 0;
}