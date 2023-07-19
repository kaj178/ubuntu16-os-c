#include <stdio.h>
#include <stdlib.h>

void phanTichThuaSoNguyenTo(int n) {
    int dem;
    printf("%d = ", n);
    for (int i = 2; i <= n; i++){
        dem = 0;
        while(n % i == 0){
            ++dem;
            n /= i;
        }
        if(dem){
            if(dem > 1) printf("%d^%d", i, dem);
            else printf("%d", i);
            if(n > i){
                printf(" * ");
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int i, doiSo = atoi(argv[1]);
    printf("Cac uoc so cua %d la ", doiSo);
    for (i = 1; i <= doiSo; i++) {
        if (doiSo % i == 0) {
            printf("%d  ", i);
        }
    }
    printf("\n");

    phanTichThuaSoNguyenTo(doiSo);

    printf("\n");
    return 0;
} 