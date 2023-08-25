#ifndef __INOUT_H__
#define __INOUT_H__

#include "square_solver.h"

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

#endif //__INOUT_H__
