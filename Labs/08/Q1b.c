#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 10000000
#define THREADS 10

float *A, *B, *C;

void* add(void *arg) {
    int idx = (int)(long)arg;
    int start = idx * (SIZE / THREADS);
    int end = (idx == THREADS - 1) ? SIZE : start + (SIZE / THREADS);

    printf("Start Sum (thread #%d)\n", idx + 1);
    for (int i = start; i < end; i++)
        C[i] = A[i] + B[i];
    printf("End Sum (thread #%d)\n", idx + 1);

    return NULL;
}

int main() {
    A = malloc(SIZE * sizeof(float));
    B = malloc(SIZE * sizeof(float));
    C = malloc(SIZE * sizeof(float));

    srand(42);
    for (int i = 0; i < SIZE; i++) {
        A[i] = (float)rand() / RAND_MAX;
        B[i] = (float)rand() / RAND_MAX;
    }

    pthread_t t[THREADS];
    for (int i = 0; i < THREADS; i++)
        pthread_create(&t[i], NULL, add, (void *)(long)i);

    for (int i = 0; i < THREADS; i++)
        pthread_join(t[i], NULL);

    for (int i = 0; i < 100; i++) {
        printf("%.3f ", C[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }

    free(A); free(B); free(C);
    return 0;
}

