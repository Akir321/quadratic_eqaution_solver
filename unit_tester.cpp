#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "colors.h"
#include "square_solver.h"
#include "unit_tester.h"

int main(const int argc, const char *argv[])
{
    printf("##" YELLOW("STARTING TESTING SOLVE_SQUARE\n"));
    const char *defaultFileName = "test.txt";

    if (argc <= 1) {
        printf(RED("NO FILE NAME GIVEN\n"));
        printf(RED("RUNNING DEFAULT TEST INSTEAD\n"));
        printf(MAGENTA("#[%s]\n"), defaultFileName);
        runTestSolveSquare(defaultFileName);
    }
    
    for (int i = 1; i < argc; i++) {
        const char *testFileName = argv[i];
        printf(MAGENTA("#[%s]\n"), testFileName);
        runTestSolveSquare(testFileName);
    }
}

bool rootsEqual(const eqRoots *roots, const eqRoots *rootsRef, int nRoots)
{
    assert(roots);
    assert(rootsRef);
    assert(roots != rootsRef);

    switch (nRoots) {
        case NO_ROOTS:  
            return true;

        case INF_ROOTS:
            return true;

        case ONE_ROOT:
            return doubleEqual(roots->x1, rootsRef->x1);

        case TWO_ROOTS:
            return doubleEqual(roots->x1, rootsRef->x1) &&
                   doubleEqual(roots->x2, rootsRef->x2);

        default:
            return false;
    }
}

int testSolveSquare(const testData* data)
{
    eqRoots roots = {0, 0};
    int nRoots = solveSquare(&(data->coeffs), &roots);

    if (nRoots != data->nRoots || !(rootsEqual(&roots, &(data->roots), nRoots))) {
        printf("#" RED("TEST %d") " %s " RED("FAILED" ) "\n",
                data->testNumber, data->name);

        printf(RED("\tCOEFFICIENTS: a = %lf, b = %lf, c = %lf\n"), 
                data->coeffs.a, data->coeffs.b, data->coeffs.c);

        printf(RED("\tOUTPUT:   x1 = %lf, x2 = %lf, nRoots = %d\n"),
                roots.x1, roots.x2, nRoots);

        printf(GREEN("\tEXPECTED: x1 = %lf, x2 = %lf, nRoots = %d\n"),
                data->roots.x1, data->roots.x2, data->nRoots);

        return 0;
    }

    printf ("#" GREEN("TEST %d") " %s" GREEN(" OK\n"), data->testNumber, data->name);
    return 1;
}

void runTestSolveSquare(const char *fileName)
{
    int passedCount = 0;
    FILE *fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf(RED("ERROR:") RED_ITALICS ("TEST FILE NOT FOUND\n"));
        return;
    }

    testData data = {{NAN, NAN, NAN}, {NAN, NAN}, 0, 0, ""};
    int scanned = 0;
    int testCount = 0;

    while (true) {
        // test file has a special format
        scanned = fscanf(fp, "%32[^:]: [%d %lf %lf %lf %lf %lf %d]\n", 
                         data.name,
                         &data.testNumber, 
                         &data.coeffs.a, &data.coeffs.b, &data.coeffs.c,
                         &data.roots.x1, &data.roots.x2,
                         &data.nRoots);

        if (scanned == AMOUNT_OF_PARAMETERS) {
            testCount++;
        }

        if (scanned == EOF) {
            break;
        }

        if (scanned == 0) {
            int symbol = fgetc(fp);

            if (symbol != ']' && symbol != '[' && symbol != ':') {
                printf(RED("ERROR:") RED_ITALICS(" BAD CHARACTERS IN TEST FILE\n"));
            }
        }
        else if (scanned < AMOUNT_OF_PARAMETERS) {
            printf(RED("ERROR:") RED_ITALICS(" COULDN'T READ THE EXPECTED AMOUNT OF PARAMETERS\n"));
        }
        else {
            passedCount += testSolveSquare(&data);
        }
    } 
    
    if (passedCount == testCount) {
        printf ("##" GREEN("PASSED ALL %d TESTS"), testCount);
    }
    else {
        printf("##" GREEN("PASSED %d TESTS,") RED(" FAILED %d TESTS\n"), 
               passedCount, testCount - passedCount);
    }
}
