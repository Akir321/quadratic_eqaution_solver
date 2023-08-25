#include "square_solver.h"
#include "inout.h"
#include "colors.h"

void printRoots(int nRoots, eqRoots roots)
{
    switch(nRoots) {
        case NO_ROOTS:
            printf(GREEN("No roots\n"));
            break;

        case ONE_ROOT:
            printf(YELLOW("1 root\nx = %lg\n"), roots.x1);
            break;

        case TWO_ROOTS:
            printf(GREEN("2 roots\nx1 = %lg\nx2 = %lg\n"), roots.x1, roots.x2);
            break;

        case INF_ROOTS:
            printf(BLUE("Any number\n"));
            break;

        default:
            printf(RED("main(): ERROR: nRoots = %d\n"), nRoots);
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
    printf(greenCursive); // the user types with green cursive

    while (!scanned){

        if (scanf("%lf", &coeff)) {
            assert(isfinite(coeff));
            assert(!isnan(coeff));
            scanned = true;
        }
        else {
            printf(RED_CURSIVE("\nYou need to enter numbers\n\n"));
            printf(greenCursive);
            clear();
        }
    }

    printf(defaultColor);
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