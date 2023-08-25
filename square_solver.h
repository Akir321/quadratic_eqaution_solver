#ifndef __SQUARE_SOLVER_H__
#define __SQUARE_SOLVER_H__

#include <stdio.h>
#include <math.h>
#include <assert.h>

/**
 * @brief The precision of comparing
 * 
 */
const double EPSILON = 0.000001; 

/**
 * @brief Enumerates possible amounts of roots
 * 
 */
enum NUMBERS_OF_ROOTS {
    NO_ROOTS  =  0,
    ONE_ROOT  =  1,
    TWO_ROOTS =  2,
    INF_ROOTS = -1
};

/**
 * @brief Coefficients for a quadratic equation
 * 
 */
struct sqCoeffs {
    double a = 0;
    double b = 0;
    double c = 0;
};

/**
 * @brief Coefficients for a liinear equation
 * 
 */
struct linCoeffs {
    double a = 0;
    double b = 0;
};

/**
 * @brief Roots that an equation has
 * 
 */
struct eqRoots{
    double x1 = 0;
    double x2 = 0;
};

/**
 * @brief Determines if a double number is equal to zero
 * 
 * @param [in] number 
 * @return true if it is zero
 * @return false if it is not zero
 */
bool isZero (double number);

/**
 * @brief Determines if two double numbers are equal
 * 
 * @param [in] a, b 
 * @return true if they are equal
 * @return false if they are not equal
 */
bool doubleEqual(double a, double b);

/**
 * @brief Solves a linear equation 
 * 
 * @param [in] coeffs 
 * @param [out] roots 
 * @return int The amount of roots this equation has 
 */
int solveLinear(const linCoeffs* coeffs, eqRoots* roots);

/**
 * @brief Solves a quadratic equation
 * 
 * @param [in] coeffs 
 * @param [out] roots 
 * @return int The amount of roots this equation has
 */
int solveSquare(const sqCoeffs* coeffs, eqRoots* roots);

#endif //__SQUARE_SOLVER_H__