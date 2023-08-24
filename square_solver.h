#ifndef __SQUARE_SOLVER_H__
#define __SQUARE_SOLVER_H__

#include <stdio.h>
#include <math.h>
#include <assert.h>

const double EPSILON = 0.000001; 

enum NUMBERS_OF_ROOTS {
    NO_ROOTS  =  0,
    ONE_ROOT  =  1,
    TWO_ROOTS =  2,
    INF_ROOTS = -1
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

struct testData{
    sqCoeffs coeffs;
    eqRoots roots;
    int nRoots;
    int testNumber;
};

bool isZero (double number);

bool floatEqual(double a, double b);

int solveLinear(linCoeffs coeffs, eqRoots* roots);

int solveSquare(sqCoeffs coeffs, eqRoots* roots);

void clear(void);

double getCoeff(void);

sqCoeffs inputCoeffs(void);

void printRoots(int nRoots, eqRoots roots);

int testSolveSquare(const testData* data);

void runTestSS(void);

bool rootsEqual(eqRoots roots, eqRoots rootsRef, int nRoots);

#endif //__SQUARE_SOLVER_H__