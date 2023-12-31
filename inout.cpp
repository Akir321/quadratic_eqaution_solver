#include <math.h>
#include <assert.h>
#include <stdio.h>
#include "square_solver.h"
#include "inout.h"
#include "colors.h"

void printRoots(int nRoots, const eqRoots *roots)
{
    assert(roots);

    switch(nRoots) {
        case NO_ROOTS:
            printf(RED("No roots\n"));
            break;

        case ONE_ROOT:
            printf(YELLOW("1 root\nx = %lg\n"), roots->x1);
            break;

        case TWO_ROOTS:
            printf(GREEN("2 roots\nx1 = %lg\nx2 = %lg\n"), roots->x1, roots->x2);
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
    printf(greenItalics); // the user types with green italics

    while (!scanned) {

        if (scanf("%lf", &coeff)) {
            scanned = true;
        }
        else {
            printf(RED_ITALICS("\nYou need to enter numbers\n\n"));
            printf(greenItalics);
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
