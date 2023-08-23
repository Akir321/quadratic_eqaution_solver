#include "square_solver.h"

void printRoots(int nRoots, eqRoots roots)
{
    switch(nRoots) {
    case NO_ROOTS: printf("No roots\n");
            break;

    case ONE_ROOT: printf("1 root\nx = %lg\n", roots.x1);
            break;

    case TWO_ROOTS: printf("2 roots\nx1 = %lg\nx2 = %lg\n", roots.x1, roots.x2);
            break;

    case INF_ROOTS: printf("Any number\n");
                    break;

    default: printf("main(): ERROR: nRoots = %d\n", nRoots);
             break;

    }
}

void clear()
{
    while(getchar() != '\n') { }
}

double getCoeff()
{
    double coeff = 0;
    bool scanned = false;

    while (!scanned){

        if(scanf("%lf", &coeff)) {

            assert(isfinite(coeff));
            assert(!isnan(coeff));

            scanned = true;
        }
        else {
            printf("\nYou need to enter numbers\n\n");
            clear();
        }
    }

    return coeff;
}

sqCoeffs inputCoeffs()
{
    sqCoeffs temp = {};

    temp.a = getCoeff();
    temp.b = getCoeff();
    temp.c = getCoeff();

    return temp;
}