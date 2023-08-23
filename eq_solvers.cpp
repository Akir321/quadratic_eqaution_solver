#include "square_solver.h"

bool isZero (double number)
{

    assert(!isnan(number));
    assert(isfinite(number));

    if (number < 0) number = -number;
    if (number < EPSILON) return true;
    return false;
}

int solveLinear(double coeffs[], const int nCoeffs, double roots[], const int nRoots)
{
    double a = coeffs[0];
    double b = coeffs[1];

    assert(isfinite(a));
    assert(isfinite(b));

    assert(!isnan(a));
    assert(!isnan(b));

    if (isZero(a)) return isZero(coeffs[1]) ? INF_ROOTS : NO_ROOTS;
    roots[0] = - b / a;
    return ONE_ROOT;
}

int solveSquare(double coeffs[], const int nCoeffs, double roots[], const int nRoots)
{

    double a = coeffs[0];
    double b = coeffs[1];
    double c = coeffs[2];

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(!isnan(a));
    assert(!isnan(b));
    assert(!isnan(c));

    if (isZero(a)) {
        if (isZero(b)) return isZero(c) ? INF_ROOTS : NO_ROOTS;

        return solveLinear(coeffs + 1, nCoeffs - 1, roots, nRoots - 1);
    }

    double D = b*b - 4*a*c;
    if (D < 0) return NO_ROOTS;

    if (D > 0) {
        double sqD = sqrt(D);
        roots[0] = (-b + sqD) / 2 / a;
        roots[1] = (-b - sqD) / 2 / a;

        if (roots[0] > roots[1]){
            double temp = roots[0];
            roots[0] = roots[1];
            roots[1] = temp;
        }
        return TWO_ROOTS;
    }

    roots[0] = -b / 2 / a;
    return ONE_ROOT;
}