#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int i, danhSachDoiSo[argc];
    for (i = 1; i < argc; i++) {
        if (atoi(argv[i])) {
            danhSachDoiSo[i] = atoi(argv[i]);
        }
    }
    
    int j;
    for (j = 0; j < sizeof(danhSachDoiSo); j++) {
        printf("%d  ", danhSachDoiSo[j]);
    }
    

    printf("\n");
    return 0;
}