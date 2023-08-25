#include "square_solver.h"
#include "unit_tester.h"

#include <stdio.h>

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
    int nRoots = solveSquare(&(data->coeffs), &roots);

    if (nRoots != data->nRoots || !(rootsEqual(roots, data->roots, nRoots))){

        printf ("#TEST %d %s FAILED\n", data->testNumber, data->name);

        printf (" COEFFICIENTS: a = %lf, b = %lf, c = %lf\n", data->coeffs.a, 
                                data->coeffs.b, data->coeffs.c);

        printf (" OUTPUT:   x1 = %lf, x2 = %lf, nRoots = %d\n",
                                roots.x1, roots.x2, nRoots);

        printf (" EXPECTED: x1 = %lf, x2 = %lf, nRoots = %d\n",
                     data->roots.x1, data->roots.x2, data->nRoots);
        return 0;
    }

    printf ("#TEST %d %s OK\n", data->testNumber, data->name);
    return 1;
}

void runTestSolveSquare()
{
    int passedCount = 0;

    const char* fileName = "test.txt";

    FILE *fp = fopen(fileName, "r");

    if (fp == NULL){
        printf("ERROR: TEST FILE NOT FOUND\n");
        return;
    }

    testData data = {{0, 0, 0}, {0, 0}, 0, 0};

    int scanned = 0;

    while (1) {

        // test file has a special format
        scanned = fscanf(fp, "%32[^:]: [%d %lf %lf %lf %lf %lf %d]\n", 
                         data.name,
                         &data.testNumber, 
                         &data.coeffs.a, &data.coeffs.b, &data.coeffs.c,
                         &data.roots.x1, &data.roots.x2,
                         &data.nRoots);

        if(scanned == EOF) {
            break;
        }

        if (scanned == 0) {
            int symbol = fgetc(fp);

            if (symbol != ']' && symbol != '[') {
                printf("BAD CHARACTERS IN TEST FILE\n");
            }
        }
        else if (scanned < 7) {
            printf("ERROR: COULDN'T READ THE EXPECTED AMOUNT OF PARAMETERS\n");
        }
        else {
            passedCount += testSolveSquare(&data);
        }
    } 
    
    printf("##PASSED %d TESTS, FAILED %d TESTS\n", passedCount, N_TESTS - passedCount);
}

int main()
{
    printf("##STARTING TESTING SOLVE_SQUARE\n");
    runTestSolveSquare();
}