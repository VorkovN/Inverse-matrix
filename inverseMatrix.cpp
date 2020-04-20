//#include "transpose.cpp"
//#include "determinant.cpp"

double **inverseMatrix(double **m, int *nstr, int *nstb) {
    double det = determinant(m, nstr, nstb, 0);//always write 0
    //printf("determinant: %f\n", det);
    if (det == 0) {
        printf("inverse matrix isn't exist\n");
        return nullptr;
    } else {
        double **mm = new double *[*nstr];
        for (int st = 0; st < *nstr; st++) {
            mm[st] = new double[*nstb];
        }
        for (int i = 0; i < *nstr; i++) {
            for (int j = 0; j < *nstb; j++) {
                double **md = new double *[*nstr ];
                for (int st = 0; st < *nstr; st++) {
                    md[st] = new double[*nstb];
                }
                for (int i2 = 0; i2 < *nstr- 1; i2++) {
                    for (int j2 = 0; j2 < *nstb - 1; j2++) {
                        if (i2 >= i) {
                            if (j2 >= j){
                                md[i2][j2] = m[i2 + 1][j2 + 1];
                            }else{
                                md[i2][j2] = m[i2 + 1][j2];
                            }
                        } else {
                            if (j2 >= j) {
                                md[i2][j2] = m[i2][j2 + 1];
                            }else{
                                md[i2][j2] = m[i2][j2];
                            }
                        }
                        //printf("md[i2][j2] = %f\n", md[i2][j2]);
                    }
                }
                mm[i][j] = pow(-1, i + j) * determinant(md, nstr, nstb, 1) / det;
                //printf("mm[i][j] = %f\n", mm[i][j]);
                //printf("Minor\n");
            }
        }
        double **mt = transpose(mm, nstr, nstb);
        printf("Inverse matrix is found\n");
        return mt;
    }
}