#include "square_solver.h"
#include "inout.h"

int main()
{
    printf("# Square solver\n");
    printf("# Solves the equation ax^2 + bx + c = 0\n\n");

    printf("Enter a, b, c: ");

    sqCoeffs coeffs = inputCoeffs();

    printf("\nYour coeffs are:\na = %lg, b = %lg, c = %lg\n\n", coeffs.a, coeffs.b, coeffs.c);

    struct eqRoots roots = {};
    int nRoots = solveSquare(&coeffs, &roots);

    printRoots(nRoots, roots);
}