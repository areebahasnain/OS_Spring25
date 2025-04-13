#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int *numbers;
int count;

int average, minimum, maximum;

void* compute_average(void* arg) {
    int sum = 0;
    for (int i = 0; i < count; i++)
        sum += numbers[i];
    average = sum / count;
    return NULL;
}

void* compute_minimum(void* arg) {
    minimum = numbers[0];
    for (int i = 1; i < count; i++)
        if (numbers[i] < minimum)
            minimum = numbers[i];
    return NULL;
}

void* compute_maximum(void* arg) {
    maximum = numbers[0];
    for (int i = 1; i < count; i++)
        if (numbers[i] > maximum)
            maximum = numbers[i];
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 1;
    }

    count = argc - 1;
    numbers = malloc(count * sizeof(int));
    for (int i = 0; i < count; i++)
        numbers[i] = atoi(argv[i + 1]);

    pthread_t avg_thread, min_thread, max_thread;

    pthread_create(&avg_thread, NULL, compute_average, NULL);
    pthread_create(&min_thread, NULL, compute_minimum, NULL);
    pthread_create(&max_thread, NULL, compute_maximum, NULL);

    pthread_join(avg_thread, NULL);
    pthread_join(min_thread, NULL);
    pthread_join(max_thread, NULL);

    printf("Average: %d.\n", average);
    printf("Minimum: %d.\n", minimum);
    printf("Maximum: %d.\n", maximum);

    free(numbers);
    return 0;
}

