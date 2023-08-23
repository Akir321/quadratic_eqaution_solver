#include "square_solver.h"

// TODO: read about multiple cpp files
//       fix includes (only h)
//       linker

int main()
{
    printf("# Square solver\n");
    printf("# Solves the equation ax^2 + bx + c = 0\n\n");

    double coeffs[MAX_NCOEFFS] = {};

    printf("Enter a, b, c: ");

    inputCoeffs(coeffs, MAX_NCOEFFS);

    printf("\nYour coeffs are:\na = %lg, b = %lg, c = %lg\n\n", coeffs[0], coeffs[1], coeffs[2]);

    double roots[MAX_NROOTS] = {};
    int nRoots = solveSquare(coeffs, MAX_NCOEFFS, roots, MAX_NROOTS);

    printRoots(nRoots, roots);
}