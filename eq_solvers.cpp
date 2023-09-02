#include <assert.h>
#include <math.h>
#include "square_solver.h"

bool doubleEqual(double a, double b)
{
    assert(!isnan(a));
    assert(!isnan(b));

    assert(isfinite(a));
    assert(isfinite(b));
    
    return fabs(a - b) < EPSILON ?  true : false; 
}

bool isZero (double number)
{
    assert(!isnan(number));
    assert(isfinite(number));

    return doubleEqual(number, 0);
}

numberOfRoots solveLinear(const linCoeffs *coeffs, eqRoots *roots)
{
    assert(isfinite(coeffs->a));
    assert(isfinite(coeffs->b));

    assert(!isnan(coeffs->a));
    assert(!isnan(coeffs->b));

    assert(roots != nullptr);

    if (isZero(coeffs->a)) {
        return isZero(coeffs->b) ? INF_ROOTS : NO_ROOTS;
    } 

    roots->x1 = - coeffs->b / coeffs->a;
    return ONE_ROOT;
}

numberOfRoots solveSquare(const sqCoeffs *coeffs, eqRoots *roots)
{
    assert(isfinite(coeffs->a));
    assert(isfinite(coeffs->b));
    assert(isfinite(coeffs->c));

    assert(!isnan(coeffs->a));
    assert(!isnan(coeffs->b));
    assert(!isnan(coeffs->a));

    assert(roots != nullptr);

    if (isZero(coeffs->a)) {
        if (isZero(coeffs->b)) {
            return isZero(coeffs->c) ? INF_ROOTS : NO_ROOTS;
        }

        linCoeffs new_coeffs = {coeffs->b, coeffs->c};
        return solveLinear(&new_coeffs, roots);
    }

    double D = coeffs->b*coeffs->b - 4*coeffs->a*coeffs->c;
    if (D < 0) {
        return NO_ROOTS;
    } 

    if (D > 0) {
        double sqD = sqrt(D);
        roots->x1 = (-coeffs->b + sqD) / (2 * coeffs->a);
        roots->x2 = (-coeffs->b - sqD) / (2 * coeffs->a);

        if (roots->x1 > roots->x2){
            swap(&roots->x1, &roots->x2);
        }
        return TWO_ROOTS;
    }

    roots->x1 = -coeffs->b / (2 * coeffs->a);
    return ONE_ROOT;
}

void swap(double *a, double *b)
{
    // *a += *b;
    // *b -= *a;
    // *b = -*b;
    // *a -= *b;

    assert(a);
    assert(b);
    
    double temp = *a;
    *a = *b;
    *b = temp;
}
