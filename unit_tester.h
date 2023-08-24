#ifndef __UNIT_TESTER_H__
#define __UNIT_TESTER_H__

#include "square_solver.h"

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
void runTestSolveSquare(void);

/**
 * @brief Determines if the roots that solveSquare() has calculated are equal to the reference roots
 * 
 * @param [in] roots, rootsRef 
 * @param [in] nRoots 
 * @return true if the roots are equal
 * @return false if the roots are not equal
 */
bool rootsEqual(eqRoots roots, eqRoots rootsRef, int nRoots);

#endif //__UNIT_TESTER_H__