#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char ** const argv) {
    pid_t pid;
    int sum = 0;
    int div = 0;
    int n = atoi(argv[1]);
    pid = fork();
    if (n == 0) {
        printf("Error, doi so truyen vao khong hop le");
    }
    if (pid == 0) {
        while (n >= 1) {
            if (n == 1) {
                printf("%d\n", n);
                break;
            }
            printf("%d\n", n);
            if (n % 2 == 0) {
                n = n/2;
            }
            else {
                n = 3 * n + 1;
            }
        }
    }
    else if (pid > 0) {
        wait(NULL);
        printf("Ket thuc tien trinh con");
    }
    return 0;
}