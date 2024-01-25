#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePlateau(int x, int y, int density) {
    FILE *file = fopen("plateau.txt", "w");

    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    fprintf(file, "%d.%do\n", y, x);

    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            char cell = (rand() % (2 * y) < density) ? 'x' : '.';
            fprintf(file, "%c", cell);
            printf("%c", cell);
        }
        fprintf(file, "\n");
        printf("\n");
    }

    fclose(file);
}

int main(int argc, char const *argv[]) {
    if (argc != 4) {
        printf("Utilisation : %s x y density\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int density = atoi(argv[3]);

    generatePlateau(x, y, density);

    printf("Plateau généré et enregistré dans plateau.txt.\n");

    return 0;
}
