#include <stdio.h>
#include <stdlib.h> 
#include "first.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    float A, deltaX;
    if (fscanf(file, "%f", &A) != 1) {
        fprintf(stderr, "Error reading A\n");
        fclose(file);
        return EXIT_FAILURE;
    }
    if (fscanf(file, "%f", &deltaX) != 1) {
        fprintf(stderr, "Error reading deltaX\n");
        fclose(file);
        return EXIT_FAILURE;
    }
    int k;
    if (fscanf(file, "%d", &k) != 1) {
            fprintf(stderr, "Error reading k\n");
            fclose(file);
            return EXIT_FAILURE;
    }

    fclose(file);

    printf("Derivative cos(x) in A: ");
    printf("%f ", Derivative(A, deltaX));
    printf("\n");
    printf("Pi: ");
    printf("%f ", Pi(k));
    printf("\n");

    return 0;
}