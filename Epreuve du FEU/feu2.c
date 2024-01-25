/*Créez un programme qui reçoit une expression arithmétique dans une chaîne de caractères et en retourne le résultat après l’avoir calculé.

Vous devez gérer les 5 opérateurs suivants : “+” pour l’addition, “-” pour la soustraction, “*” la multiplication, “/” la division et “%” le modulo.

Exemple d’utilisation :


$> ruby exo.rb "4 + 21 * (1 - 2 / 2) + 38"
42


Vous pouvez partir du principe que la chaîne de caractères donnée en argument sera valide.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Fonction récursive pour évaluer les expressions entre parenthèses
int evaluateParentheses(char tab[100][100], int start, int end) {
    int result = 0;
    int openParentheses = 0;
    int closeParentheses = 0;
    int n = 0;

    // Comptage du nombre de parenthèses ouvrantes et fermantes
    for (int i = start; i < end; ++i) {
        if (strcmp(tab[i], "(") == 0) {
            openParentheses++;
        } else if (strcmp(tab[i], ")") == 0) {
            closeParentheses++;
        }
    }

    // Si le nombre de parenthèses ouvrantes est différent du nombre de parenthèses fermantes,
    // alors les parenthèses sont mal équilibrées
    if (openParentheses != closeParentheses) {
        printf("Les parenthèses ne sont pas équilibrées.\n");
        exit(1);
    }

    // Réalisation des opérations à l'intérieur des parenthèses
    for (int i = start; i < end; ++i) {
        // Si une parenthèse ouvrante est trouvée, on trouve la parenthèse correspondante fermante
        if (strcmp(tab[i], "(") == 0) {
            int j = i + 1;
            int count = 1;

            // Trouver la parenthèse fermante correspondante
            while (count != 0) {
                if (strcmp(tab[j], "(") == 0) {
                    count++;
                } else if (strcmp(tab[j], ")") == 0) {
                    count--;
                }
                j++;
            }

            // Récursivement évaluer les parenthèses internes
            int innerResult = evaluateParentheses(tab, i + 1, j - 1);

            // Remplacer l'expression entre parenthèses par son résultat
            char temp[100];
            sprintf(temp, "%d", innerResult);
            strcpy(tab[i], temp);
            for (int k = i + 1; k < j; ++k) {
                strcpy(tab[k], "");
            }

            // Mettre à jour la position de la boucle
            i = j - 1;
        }
    }

    // Évaluation de l'expression après la résolution des parenthèses
    for (int i = start; i < end; ++i) {
        // Votre logique pour les opérations à l'intérieur des parenthèses
        // Ajoutez ici le code pour les calculs à l'intérieur des parenthèses

        // Calcul de la mutliplication
        if (strcmp(tab[i], "*") == 0) {
            int operand1, operand2;
            int index_left = i - 1;
            int index_right = i + 1;

            // Recherche de l'opérande gauche pour l'addition, la soustraction et la multiplication
            while (index_left >= start && !(atoi(tab[index_left]) || strcmp(tab[index_left], "0") == 0)) {
            index_left--;
            }

            // Recherche de l'opérande droite pour l'addition, la soustraction et la multiplication
            while (index_right < end && !(atoi(tab[index_right]) || strcmp(tab[index_right], "0") == 0)) {
            index_right++;
            }

            // Vérification si les opérandes sont des nombres valides
            if (index_left >= start && index_right < end) {
                operand1 = atoi(tab[index_left]);
                operand2 = atoi(tab[index_right]);
                
                result = operand1 * operand2;
 
                sprintf(tab[index_left], "%d", result); // Mise à jour de l'opérande gauche
                strcpy(tab[i], ""); // Effacement de l'opérateur +
                strcpy(tab[index_right], ""); // Effacement de l'opérande droite
            }
        }
        //Division
        if (strcmp(tab[i], "/") == 0) {
            int operand1, operand2;
            int index_left = i - 1;
            int index_right = i + 1;

            // Recherche de l'opérande gauche pour l'addition, la soustraction et la multiplication
            while (index_left >= start && !(atoi(tab[index_left]) || strcmp(tab[index_left], "0") == 0)) {
            index_left--;
            }

            // Recherche de l'opérande droite pour l'addition, la soustraction et la multiplication
            while (index_right < end && !(atoi(tab[index_right]) || strcmp(tab[index_right], "0") == 0)) {
            index_right++;
            }

            // Vérification si les opérandes sont des nombres valides
            if (index_left >= start && index_right < end) {
                operand1 = atoi(tab[index_left]);
                operand2 = atoi(tab[index_right]);
 
                
                result = operand1 / operand2;

                sprintf(tab[index_left], "%d", result); // Mise à jour de l'opérande gauche
                strcpy(tab[i], ""); // Effacement de l'opérateur +
                strcpy(tab[index_right], ""); // Effacement de l'opérande droite
            }
        }
        //Modulo
        if (strcmp(tab[i], "%") == 0) {
            int operand1, operand2;
            int index_left = i - 1;
            int index_right = i + 1;

            // Recherche de l'opérande gauche pour l'addition, la soustraction et la multiplication
            while (index_left >= start && !(atoi(tab[index_left]) || strcmp(tab[index_left], "0") == 0)) {
            index_left--;
            }

            // Recherche de l'opérande droite pour l'addition, la soustraction et la multiplication
            while (index_right < end && !(atoi(tab[index_right]) || strcmp(tab[index_right], "0") == 0)) {
            index_right++;
            }

            // Vérification si les opérandes sont des nombres valides
            if (index_left >= start && index_right < end) {
                operand1 = atoi(tab[index_left]);
                operand2 = atoi(tab[index_right]);
                
                result = operand1 % operand2;

                sprintf(tab[index_left], "%d", result); // Mise à jour de l'opérande gauche
                strcpy(tab[i], ""); // Effacement de l'opérateur +
                strcpy(tab[index_right], ""); // Effacement de l'opérande droite
            }
        }
        
    }    
    for (int i = start; i < end; ++i) {
        if (strcmp(tab[i], "+") == 0) {
            int operand1, operand2;
            int index_left = i - 1;
            int index_right = i + 1;

        	// Recherche de l'opérande gauche
			// Recherche de l'opérande gauche pour l'addition, la soustraction et la multiplication
            while (index_left >= start && !(atoi(tab[index_left]) || strcmp(tab[index_left], "0") == 0)) {
            index_left--;
            }

            // Recherche de l'opérande droite pour l'addition, la soustraction et la multiplication
            while (index_right < end && !(atoi(tab[index_right]) || strcmp(tab[index_right], "0") == 0)) {
            index_right++;
            }

            // Vérification si les opérandes sont des nombres valides
            if (index_left >= start && index_right < end) {
                operand1 = atoi(tab[index_left]);
                operand2 = atoi(tab[index_right]);

                // Calcul de l'addition
                result = operand1 + operand2;
                sprintf(tab[index_left], "%d", result); // Mise à jour de l'opérande gauche
                strcpy(tab[i], ""); // Effacement de l'opérateur +
                strcpy(tab[index_right], ""); // Effacement de l'opérande droite
            }
        }
        if (strcmp(tab[i], "-") == 0) {
            int operand1, operand2;
            int index_left = i - 1;
            int index_right = i + 1;

            // Recherche de l'opérande gauche pour l'addition, la soustraction et la multiplication
            while (index_left >= start && !(atoi(tab[index_left]) || strcmp(tab[index_left], "0") == 0)) {
            index_left--;
            }

            // Recherche de l'opérande droite pour l'addition, la soustraction et la multiplication
            while (index_right < end && !(atoi(tab[index_right]) || strcmp(tab[index_right], "0") == 0)) {
            index_right++;
            }

            // Vérification si les opérandes sont des nombres valides
            if (index_left >= start && index_right < end) {
                operand1 = atoi(tab[index_left]);
                operand2 = atoi(tab[index_right]);

                // Calcul de l'addition
                result = operand1 - operand2;
                sprintf(tab[index_left], "%d", result); // Mise à jour de l'opérande gauche
                strcpy(tab[i], ""); // Effacement de l'opérateur +
                strcpy(tab[index_right], ""); // Effacement de l'opérande droite
            }
        }
    }



    return result;
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("Veuillez fournir une suite de caractères en argument.\n");
        return 1;
    }

    // Initialisation des variables
    const char *input = argv[1];
    char tab[100][100];
    int len = strlen(input);
    int n = 0;
    int result = 0;

    // Parcours de la chaîne d'entrée pour extraire les éléments
    for (int i = 0; i < len; ++i) {
        if (!isspace(input[i])) {
            if (isdigit(input[i])) {
                int j = i;
                while (j < len && (isdigit(input[j]))) {
                    j++;
                }
                strncpy(tab[n], &input[i], j - i);
                tab[n][j - i] = '\0';
                n++;
                i = j - 1;
            } else if (input[i] == '(' || input[i] == ')' || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'|| input[i] == '%') {
                tab[n][0] = input[i];
                tab[n][1] = '\0';
                n++;
            }
        }
    }

    // Évaluation des expressions entre parenthèses
    result = evaluateParentheses(tab, 0, n);

    // Affichage du résultat final
    printf("Résultat = %d\n", result);
  

    return 0;
}
//Validé
