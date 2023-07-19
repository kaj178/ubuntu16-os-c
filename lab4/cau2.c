#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* printPrime(void* arg) {
    int n = *((int*) arg);
    int i, j;
    for (i = 2; i <= n; i++) {
        for (j = 2; j <= i; j++) {
            if (i == j) printf("%d\n", i);
            if (i % j == 0) break;
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char ** argv) {
    if (argc < 2) {
        printf("Thieu doi so truyen vao");
        return 1;
    }

    pthread_t thread;
    int n = atoi(argv[1]);

    pthread_create(&thread, NULL, printPrime, &n);
    pthread_join(thread, NULL);
    return 0;
}