#include "square_solver.h"
#include "inout.h"
#include "colors.h"

int main()
{
    printf("# " green "Square solver\n" endColor);
    printf("# " green "Solves the equation ax^2 + bx + c = 0\n\n" endColor);

    printf(green "Enter a, b, c: " endColor);

    sqCoeffs coeffs = inputCoeffs();

    printf(green "\nYour coeffs are:\na = %lg, b = %lg, c = %lg\n\n" endColor,
                                         coeffs.a, coeffs.b, coeffs.c);

    struct eqRoots roots = {};
    int nRoots = solveSquare(&coeffs, &roots);

    printRoots(nRoots, roots);

    printf("#"  green "Your equation is solved\n" endColor);
}