#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000

int main() {
    float *A = malloc(SIZE * sizeof(float));
    float *B = malloc(SIZE * sizeof(float));
    float *C = malloc(SIZE * sizeof(float));

    srand(42);
    for (int i = 0; i < SIZE; i++) {
        A[i] = (float)rand() / RAND_MAX;
        B[i] = (float)rand() / RAND_MAX;
    }

    for (int i = 0; i < SIZE; i++) {
        C[i] = A[i] + B[i];
    }
    
    printf("First 100 values of C:\n");
    for (int i = 0; i < 100; i++) {
        printf("%.3f ", C[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }

    free(A); free(B); free(C);
    return 0;
}

