#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Current process is: %d\n", getpid());
    printf("Parent process is: %d, \n", getppid());
    return 0;
}