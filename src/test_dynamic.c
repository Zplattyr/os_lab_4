#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

typedef float (*Derivative)(float A, float deltaX);
typedef float (*Pi)(int k);

int main() {
    void *libHandle;
    int number_lib = 1;
    Derivative derivative;
    Pi pi;
    libHandle = dlopen("./libfirst.so", RTLD_LAZY);
    int choice = 1;  

    while (choice != -1) {
        printf("Select operation (-1 - exit, 0 - change lib, 1 - calculate derivative, 2 - calculate pi): ");
        scanf("%d", &choice);

        if (choice == -1) {
            break;
        } else if (choice == 0) {

            if (libHandle) {
                dlclose(libHandle);
            }

            if (number_lib == 2) {
                libHandle = dlopen("./libfirst.so", RTLD_LAZY);
                number_lib = 1;
            } else {
                libHandle = dlopen("./libsecond.so", RTLD_LAZY);
                number_lib = 2;
            }

            if (libHandle == NULL) {
                fprintf(stderr, "Error loading lib: %s\n", dlerror());
                continue;
            }
        } else if (choice == 1) {
            derivative = (Derivative)dlsym(libHandle, "Derivative");
            if (!derivative) {
                fprintf(stderr, "Error recieving function Derivative: %s\n", dlerror());
                dlclose(libHandle);
                return 1;
            }

            float A, deltaX;
            scanf("%f %f", &A, &deltaX);
            float result = derivative(A, deltaX);
            printf("Derivative in A: %f\n", result);
        } else if (choice == 2) {
            pi = (Pi)dlsym(libHandle, "Pi");
            if (!pi) {
                fprintf(stderr, "Error recieving Pi function: %s\n", dlerror());
                dlclose(libHandle);
                return 1;
            }

            int k;
            scanf("%d", &k);
            float result = pi(k);
            printf("Pi: %f\n", result);

        } else {
            printf("Некорректный выбор операции.\n");
        }
    }

    if (libHandle) {
        dlclose(libHandle);
    }

    return 0;
}