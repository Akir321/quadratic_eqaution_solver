#include "square_solver.h"
#include "unit_tester.h"

// TODO: separate header for unit_tester

const int N_TESTS = 6;

bool rootsEqual(eqRoots roots, eqRoots rootsRef, int nRoots)
{
    switch (nRoots){
    case NO_ROOTS:  return true;
    case INF_ROOTS: return true;
    case ONE_ROOT:  return doubleEqual(roots.x1, rootsRef.x1);
    case TWO_ROOTS: return doubleEqual(roots.x1, rootsRef.x1) && doubleEqual(roots.x2, rootsRef.x2);
    default: return false;
    }
}

int testSolveSquare(const testData* data)
{
    eqRoots roots = {0, 0};
    int nRoots = solveSquare(data->coeffs, &roots);

    if (nRoots != data->nRoots || !(rootsEqual(roots, data->roots, nRoots))){

        printf ("#TEST %d FAILED\n OUTPUT: x1 = %lf, x2 = %lf, nRoots = %d\n",
                                 data->testNumber, roots.x1, roots.x2, nRoots);

        printf (" EXPECTED x1 = %lf, x2 = %lf, nRoots = %d\n",
                     data->roots.x1, data->roots.x2, data->nRoots);
        return 0;
    }

    printf ("#TEST %d OK\n", data->testNumber);
    return 1;
}

// SS - ?
// print coeffs when failed
// tests using FILE *
void runTestSolveSquare()
{
    int passedCount = 0;

     const testData data[N_TESTS] = 
        {{.coeffs = {1, 2,  1}, .roots = {-1, 0}, .nRoots = ONE_ROOT,  .testNumber = 1}, 
         {.coeffs = {0, 0,  0}, .roots = { 0, 0}, .nRoots = INF_ROOTS, .testNumber = 2},
         {.coeffs = {1, 0, -4}, .roots = {-2, 2}, .nRoots = TWO_ROOTS, .testNumber = 3},
         {.coeffs = {0, 0, -4}, .roots = { 0, 0}, .nRoots = NO_ROOTS,  .testNumber = 4},
         {.coeffs = {0, 1, -4}, .roots = { 4, 0}, .nRoots = ONE_ROOT,  .testNumber = 5},
         {.coeffs = {1, 0,  0}, .roots = { 0, 0}, .nRoots = ONE_ROOT,  .testNumber = 6}};

    for(int i = 0; i < N_TESTS; i++){
        passedCount += testSolveSquare(&data[i]);
    }
    
    printf("##PASSED %d TESTS, FAILED %d TESTS\n", passedCount, N_TESTS - passedCount);
}

int main()
{
    printf("##STARTING TESTING SOLVE_SQUARE\n");
    runTestSolveSquare();
}