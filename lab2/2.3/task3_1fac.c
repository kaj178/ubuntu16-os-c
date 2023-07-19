int fac(int n) {
    int i, fac = 1;
    for (i = 1; i <= n; i++) {
        fac *= i;
    }
    return fac;
}