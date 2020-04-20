double **transpose(double **m, int *nstr, int *nstb) {

    int t = *nstb;
    *nstb = *nstr;
    *nstr = t;

    double **mt = new double *[*nstr];
    for (int st = 0; st < *nstr; st++) {
        mt[st] = new double[*nstb];
    }

    for (int i = 0; i < *nstr; i++) {
        for (int j = 0; j < *nstb; j++) {
            mt[i][j] = m[j][i];
        }
    }
    printf("Transposed matrix is found\n");
    return mt;
}