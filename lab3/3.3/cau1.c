#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void inPid(pid_t p) {
    printf("ID cua toi la %d\n", getpid());
    printf("ID cua process con la %d\n", p);
}

int main(int argc, char ** const argv) {
    printf("Current process: %d\n", getpid());
    pid_t pidBC;
    printf("Tien trinh A\n");
    inPid(pidBC);
    pidBC = fork();
    if (pidBC == 0) {
        pid_t pidDE = fork();
        if (pidDE > 0) {
            printf("Tien trinh E\n");
            inPid(pidDE);
            wait(NULL);
        }
    }
    else if (pidBC > 0) {
        printf("Tien trinh C\n");
        inPid(pidBC);
        pid_t pidH;\
        pidH = fork();
        if (pidH > 0) {
            wait(NULL);
            printf("Tien trinh H\n");
            inPid(pidH);
        }
        wait(NULL);
    }
    return 0;
}