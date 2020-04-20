double determinant(double **m, int *nstr, int *nstb, int cycle) {
    double det = 0.0;
    //printf("%dx%d\n",*nstr,*nstb);
    if (*nstr == *nstb) {
        switch (*nstr - cycle) {
            case 1:
                //printf("case1\n");
                det = m[0][0];
                break;
            case 2:
                //printf("case2\n");
                det = m[0][0] * m[1][1] - m[0][1] * m[1][0];
                break;
            case 3:
                //printf("case3\n");
                for (int k = 0; k < 3; k++) {
                    double pr = 1;
                    for (int i = 0; i < 3; i++) {
                        pr *= m[i][mod((i + k), 3)];
                    }
                    det += pr;
                    //printf("det %f\n",det);
                }
                for (int k = 0; k < 3; k++) {
                    double pr = 1;
                    for (int i = 0; i < 3; i++) {
                        pr *= m[i][mod((-i - k), 3)];
                    }
                    det -= pr;
                }
                break;
            default:
                //printf("default\n");
                for (int k = 0; k < *nstb - cycle; k++) {
                    double **md = new double *[*nstr - cycle];
                    for (int st = 0; st < *nstr - cycle; st++) {
                        md[st] = new double[*nstb - cycle];
                    }
                    for (int i = 0; i < *nstr - cycle - 1; i++) {
                        for (int j = 0; j < *nstb - cycle - 1; j++) {
                            if (j >= k) {
                                md[i][j] = m[i + 1][j + 1];
                            } else {
                                md[i][j] = m[i + 1][j];
                            }
                        }
                    }
                    //cout << "a = " << m[0][k] * pow(-1, k) << endl;
                    det += pow(-1, k) * m[0][k] * determinant(md, nstr, nstb, cycle + 1);
                }
        }
        //printf("detOut:%f\n", det);
        printf("Determinant is found\n");
        return det;
    } else {
        printf("Determinant isn't exist\n");
        return 0;
    }
}