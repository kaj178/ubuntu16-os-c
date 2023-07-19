#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    int i, count = 0;
    for (i = 0; i < argc; i++) {
        count++;
    }

    if (count > 2) {
        printf("Co qua nhieu doi so");
    } else {
        if (atoi(argv[1]) < 0) {
            printf("Doi so khong phai la so nguyen duong");
        } else {
            int j, sum = 0;
            for (j = 1; j <= atoi(argv[1]); j++) {
                sum += j;
            }
            printf("S = %d", sum);
        }
    } 

    printf("\n");
    return 0;
}