#include "mod.cpp"
#include "inputMatrix.cpp"
#include "outputMatrix.cpp"
#include "transpose.cpp"
#include "determinant.cpp"
#include "inverseMatrix.cpp"

void matrix(){
    int nstr ;
    int nstb;
    int* nstrk =&nstr;
    int* nstlb =&nstb;

    printf("Input numbers of strings:");cin >> nstr;
    printf("Input numbers of scolumns:");cin >> nstb;
    double** m = inputMatrix(nstr, nstb);
    outputMatrix(m,nstr, nstb);
    double det1 = determinant(m, nstrk, nstlb, 0);//always write 0
    printf("determinant: %f\n",det1);
    double** im = inverseMatrix(m, nstrk, nstlb);
    double det2 = determinant(im, nstrk, nstlb, 0);//always write 0
    printf("determinant: %f\n",det2);
    outputMatrix(im,nstr, nstb);
}