#include "square_solver.h"
#include "inout.h"
#include "colors.h"

int main()
{
    printf("# " RED("Square solver\n"));
    printf("# " GREEN("Solves the equation ax^2 + bx + c = 0\n\n"));

    printf(GREEN("Enter a, b, c: "));
    sqCoeffs coeffs = inputCoeffs();
    printf(GREEN("\nYour coeffs are:\na = %lg, b = %lg, c = %lg\n\n"), coeffs.a, coeffs.b, coeffs.c);

    struct eqRoots roots = {};
    int nRoots = solveSquare(&coeffs, &roots);

    printRoots(nRoots, roots);
    printf("# "  GREEN("Your equation is solved\n"));
}
