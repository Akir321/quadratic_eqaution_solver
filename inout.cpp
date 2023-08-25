#include "square_solver.h"
#include "inout.h"
#include "colors.h"

void printRoots(int nRoots, eqRoots roots)
{
    switch(nRoots) {
    case NO_ROOTS: printf(red "No roots\n" endColor);
            break;

    case ONE_ROOT: printf(yellow "1 root\nx = %lg\n" endColor, roots.x1);
            break;

    case TWO_ROOTS: printf(green "2 roots\nx1 = %lg\nx2 = %lg\n" endColor, roots.x1, roots.x2);
            break;

    case INF_ROOTS: printf(blue "Any number\n" endColor);
                    break;

    default: printf(red "main(): ERROR: nRoots = %d\n" endColor, nRoots);
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

    printf(greenCursive);

    while (!scanned){

        if(scanf("%lf", &coeff)) {

            assert(isfinite(coeff));
            assert(!isnan(coeff));

            scanned = true;
        }
        else {
            printf(redCursive "\nYou need to enter numbers\n\n" greenCursive);
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