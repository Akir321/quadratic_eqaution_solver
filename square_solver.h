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
 * @brief A special structure for easy test conducting
 * 
 */
struct testData{
    sqCoeffs coeffs;
    eqRoots roots;
    int nRoots;
    int testNumber;
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
bool floatEqual(double a, double b);

/**
 * @brief Solves a linear equation 
 * 
 * @param [in] coeffs 
 * @param [out] roots 
 * @return int The amount of roots this equation has 
 */
int solveLinear(linCoeffs coeffs, eqRoots* roots);

/**
 * @brief Solves a quadratic equation
 * 
 * @param [in] coeffs 
 * @param [out] roots 
 * @return int The amount of roots this equation has
 */
int solveSquare(sqCoeffs coeffs, eqRoots* roots);

/**
 * @brief Clears the input buffer
 * 
 */
void clear(void);

/**
 * @brief Gets one coefficient from console and returns it
 * 
 * @return double 
 */
double getCoeff(void);

/**
 * @brief Gets the Coeff object from console and returns it
 * 
 * @return sqCoeffs 
 */
sqCoeffs inputCoeffs(void);

/**
 * @brief Prints the roots and the amount of roots
 * 
 * @param [in] nRoots 
 * @param [in] roots 
 */
void printRoots(int nRoots, eqRoots roots);

/**
 * @brief Tests if solveSquare() works correctly on a pre-written test
 * 
 * Prints out the results of the test if it is incorrect
 * 
 * @param [in] data 
 * @return 1 if correct
 * @return 0 if incorrect
 */
int testSolveSquare(const testData* data);

/**
 * @brief Initializes all the pre-written tests of solveSquare()
 * 
 */
void runTestSS(void);

/**
 * @brief Determines if the roots solveSquare() has calculated are equal to the reference roots
 * 
 * @param [in] roots, rootsRef 
 * @param [in] nRoots 
 * @return true if the roots are equal
 * @return false if the roots are not equal
 */
bool rootsEqual(eqRoots roots, eqRoots rootsRef, int nRoots);

#endif //__SQUARE_SOLVER_H__