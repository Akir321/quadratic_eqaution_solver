#ifndef __SQUARE_SOLVER_H__
#define __SQUARE_SOLVER_H__

#include <stdio.h>
#include <math.h>
#include <assert.h>


const double EPSILON = 0.000001;

const int MAX_NCOEFFS = 3;
const int MAX_NROOTS  = 2; 

enum NUMBERS_OF_ROOTS {
    NO_ROOTS  = 0,
    ONE_ROOT  = 1,
    TWO_ROOTS = 2,
    INF_ROOTS = 3
};

// struct ???

bool isZero (double number);

int solveLinear(double coeffs[], const int nCoeffs, double roots[], const int nRoots);

int solveSquare(double coeffs[], const int nCoeffs, double roots[], const int nRoots);

void clear(void);

double getCoeff(void);

void inputCoeffs(double koeffs[], int nKoeffsMax);

void printRoots(int nRoots, double roots[]);

#endif //__SQUARE_SOLVER_H__