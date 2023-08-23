#ifndef __SQUARE_SOLVER_H__
#define __SQUARE_SOLVER_H__

#include <stdio.h>
#include <math.h>
#include <assert.h>

const double EPSILON = 0.000001; 

enum NUMBERS_OF_ROOTS {
    NO_ROOTS  = 0,
    ONE_ROOT  = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3
};

struct sqCoeffs {
    double a = 0;
    double b = 0;
    double c = 0;
};

struct linCoeffs {
    double a = 0;
    double b = 0;
};

struct eqRoots{
    double x1 = 0;
    double x2 = 0;
};

bool isZero (double number);

int solveLinear(linCoeffs coeffs, eqRoots* roots);

int solveSquare(sqCoeffs coeffs, eqRoots* roots);

void clear(void);

double getCoeff(void);

sqCoeffs inputCoeffs(void);

void printRoots(int nRoots, eqRoots roots);

#endif //__SQUARE_SOLVER_H__