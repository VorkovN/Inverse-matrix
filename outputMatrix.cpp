void outputMatrix(double** m, const int NSTR, const int NSTB) {

    printf("Matrix %dx%d:\n",NSTR,NSTB);
    for (int i = 0; i < NSTR; i++) {
        for ( int j = 0; j < NSTB; j++) {
            printf(" %f ", m[i][j]);
        }
        printf("\n");
    }
}