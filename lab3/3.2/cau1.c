#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    pid_t pid;
    int sum = 0;
    int div = 0;
    int n = atoi(argv[1]);
    pid = fork();
    if (pid == 0) {
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                div += i;
            }
        }
        printf("Tong cac uoc cua %d la: %d", n, div);
    }
    else if (pid > 0) {
        for (int i = 1; i <= n; i++) {
            sum += i;
        }
        printf("Tong cac so nguyen duong den %d la: %d", n, sum);
    }
    return 0;
}