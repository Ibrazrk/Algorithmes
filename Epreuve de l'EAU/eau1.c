/* Créez un programme qui affiche toutes les différentes combinaisons possibles de trois chiffres dans l’ordre croissant, dans l’ordre croissant. La répétition est volontaire.


Exemples d’utilisation :
$> python exo.py
012, 013, 014, 015, 016, 017, 018, 019, 023, 024, ... , 789
$>

987 n’est pas là parce que 789 est présent.

020 n’est pas là parce que 0 apparaît deux fois.

021 n’est pas là parce que 012 est présent.

000 n’est pas là parce que cette combinaison ne comporte pas exclusivement des chiffres différents les uns des autres.
*/


#include <stdio.h>

int main() {
    int tab1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tab2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tab3[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 10; ++i) {
        for (int j = i+1; j < 10; ++j) {
            for (int k = j+1; k < 10; ++k) {

                if (tab3[k] > tab2[j] || tab2[j] > tab1[i]) {
                    printf("%d%d%d,", tab1[i], tab2[j], tab3[k]);
                }
            }
        }
    }

    return 0;
}

//Validé