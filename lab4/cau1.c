#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double avg;
int max;
int min;

void* computeAvg(void* arg) {
    int* numbers = (int*)arg;
    double sum = 0;
    int size = numbers[0];
    int i;
    for (i = 1; i <= size; i++) {
        sum += numbers[i];
    }
    avg = sum / size;
    pthread_exit(NULL);
}

void* computeMax(void* arg) {
    int* numbers = (int*)arg;
    int size = numbers[0];
    max = numbers[1];
    int i;
    for (i = 2; i <= size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    pthread_exit(NULL);
}

void* computeMin(void* arg) {
    int* numbers = (int*)arg;
    int size = numbers[0];
    min = numbers[1];
    int i;
    for (i = 2; i <= size; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char ** argv) {
    if (argc < 2) {
        printf("Thieu doi so truyen vao");
        return 1;
    }

    // Mang chua cac doi so
    int* numbers = (int*)malloc((argc - 1) * sizeof(int));
    numbers[0] = argc - 1;
    int i;
    for (i = 1; i < argc; i++) {
        numbers[i] = atoi(argv[i]);
    }

    pthread_t thread1, thread2, thread3;

    pthread_create(&thread1, NULL, computeAvg, numbers);
    pthread_create(&thread2, NULL, computeMax, numbers);
    pthread_create(&thread3, NULL, computeMin, numbers);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("Gia tri trung binh: %.f\n", avg);
    printf("Gia tri lon nhat: %d\n", max);
    printf("Gia tri nho nhat: %d\n", min);

    free(numbers);

    return 0;
}