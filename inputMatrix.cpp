double **inputMatrix(const int NSTR, const int NSTB) {

    double **m = new double *[NSTR];
    for (int st = 0; st < NSTR; st++) {
        m[st] = new double[NSTB];
    }
    printf("Input array %dx%d\n", NSTR, NSTB);
    for (int i = 0; i < NSTR; i++) {
        for (int j = 0; j < NSTB; j++) {
            cin >> m[i][j];
        }
    }
    printf("Matrix is saved\n");
    return m;
}