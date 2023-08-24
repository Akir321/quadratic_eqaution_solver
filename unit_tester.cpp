#include "square_solver.h"

const int N_TESTS = 6;

bool floatEqual(double a, double b)
{
    return fabs(a - b) < EPSILON ?  true : false; 
}

bool rootsEqual(eqRoots roots, eqRoots rootsRef, int nRoots)
{
    switch (nRoots){
    case NO_ROOTS:  return true;
    case INF_ROOTS: return true;
    case ONE_ROOT:  return floatEqual(roots.x1, rootsRef.x1);
    case TWO_ROOTS: return floatEqual(roots.x1, rootsRef.x1) && floatEqual(roots.x2, rootsRef.x2);
    default: return false;
    }
}

int testSolveSquare(const testData* data)
{
    eqRoots roots = {0, 0};
    int nRoots = solveSquare(data->coeffs, &roots);

    if (nRoots != data->nRoots || !(rootsEqual(roots, data->roots, nRoots))){

        printf ("#TEST %d FAILED x1 = %lf, x2 = %lf, nRoots = %d\n",
                                 data->testNumber, roots.x1, roots.x2, nRoots);

        printf (" EXPECTED x1 = %lf, x2 = %lf, nRoots = %d\n",
                     data->roots.x1, data->roots.x2, data->nRoots);
        return 0;
    }

    printf ("#TEST OK\n");
    return 1;
}

void runTestSS()
{
    int passedCount = 0;

     const testData data[N_TESTS] = 
        {{.coeffs = {1, 2,  1}, .roots = {-1, 0}, .nRoots = ONE_ROOT,  .testNumber = 1}, 
         {.coeffs = {0, 0,  0}, .roots = { 0, 0}, .nRoots = INF_ROOTS, .testNumber = 2},
         {.coeffs = {1, 0, -4}, .roots = {-2, 2}, .nRoots = TWO_ROOTS, .testNumber = 1},
         {.coeffs = {0, 0, -4}, .roots = { 0, 0}, .nRoots = NO_ROOTS,  .testNumber = 1},
         {.coeffs = {0, 1, -4}, .roots = { 4, 0}, .nRoots = ONE_ROOT,  .testNumber = 1},
         {.coeffs = {1, 0,  0}, .roots = { 0, 0}, .nRoots = ONE_ROOT,  .testNumber = 1}};

    for(int i = 0; i < N_TESTS; i++){
        passedCount += testSolveSquare(&data[i]);
    }
    
    printf("##PASSED %d TESTS, FAILED %d TESTS\n", passedCount, N_TESTS - passedCount);
}

int main()
{
    printf("##STARTING TESTING SOLVE_SQUARE\n");
    runTestSS();
}