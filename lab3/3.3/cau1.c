#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void inPid(pid_t p) {
    printf("ID cua toi la %d\n", getpid());
    printf("ID cua process con la %d\n", p);
}

