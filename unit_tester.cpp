#include "square_solver.h"
#include "unit_tester.h"
#include "colors.h"

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

        printf ("#" red "TEST %d" endColor " %s " red "FAILED" endColor "\n",
                                             data->testNumber, data->name);

        printf (red " COEFFICIENTS: a = %lf, b = %lf, c = %lf\n" endColor, data->coeffs.a, 
                                data->coeffs.b, data->coeffs.c);

        printf (red " OUTPUT:   x1 = %lf, x2 = %lf, nRoots = %d\n" endColor,
                                roots.x1, roots.x2, nRoots);

        printf (green " EXPECTED: x1 = %lf, x2 = %lf, nRoots = %d\n" endColor,
                     data->roots.x1, data->roots.x2, data->nRoots);
        return 0;
    }

    printf ("#" green "TEST %d" endColor " %s" green " OK\n" endColor, data->testNumber, data->name);
    return 1;
}

void runTestSolveSquare()
{
    int passedCount = 0;

    const char* fileName = "test.txt";

    FILE *fp = fopen(fileName, "r");

    if (fp == NULL){
        printf(red "ERROR:" redCursive "TEST FILE NOT FOUND\n" endColor);
        return;
    }

    testData data = {{0, 0, 0}, {0, 0}, 0, 0};

    int scanned = 0;

    while (true) {
        // test file has a special format
        scanned = fscanf(fp, "%32[^:]: [%d %lf %lf %lf %lf %lf %d]\n", 
                         data.name,
                         &data.testNumber, 
                         &data.coeffs.a, &data.coeffs.b, &data.coeffs.c,
                         &data.roots.x1, &data.roots.x2,
                         &data.nRoots);

        if (scanned == EOF) {
            break;
        }

        if (scanned == 0) {
            int symbol = fgetc(fp);

            if (symbol != ']' && symbol != '[') {
                printf(red "ERROR:" redCursive " BAD CHARACTERS IN TEST FILE\n" endColor);
            }
        }
        else if (scanned < 7) {
            printf(red "ERROR:" redCursive " COULDN'T READ THE EXPECTED AMOUNT OF PARAMETERS\n" endColor);
        }
        else {
            passedCount += testSolveSquare(&data);
        }
    } 
    
    if (passedCount == N_TESTS){
        printf ("##" green "PASSED ALL %d TESTS" endColor, N_TESTS);
    }
    else {
        printf("##" green "PASSED %d TESTS," red " FAILED %d TESTS\n" endColor, 
                                        passedCount, N_TESTS - passedCount);
    }
}

int main()
{
    printf("##" yellow "STARTING TESTING SOLVE_SQUARE\n" endColor);
    runTestSolveSquare();
}