#include <stdio.h>

#include "colors.h"
#include "square_solver.h"
#include "unit_tester.h"

bool rootsEqual(eqRoots roots, eqRoots rootsRef, int nRoots)
{
    switch (nRoots){
        case NO_ROOTS:  
            return true;

        case INF_ROOTS:
            return true;

        case ONE_ROOT:
            return doubleEqual(roots.x1, rootsRef.x1);

        case TWO_ROOTS:
            return doubleEqual(roots.x1, rootsRef.x1) &&
                   doubleEqual(roots.x2, rootsRef.x2);

        default:
            return false;
    }
}

int testSolveSquare(const testData* data)
{
    eqRoots roots = {0, 0};
    int nRoots = solveSquare(&(data->coeffs), &roots);

    if (nRoots != data->nRoots || !(rootsEqual(roots, data->roots, nRoots))) {
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

void runTestSolveSquare()
{
    int passedCount = 0;
    const char* fileName = "test.txt";
    FILE *fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf(RED("ERROR:") RED_CURSIVE ("TEST FILE NOT FOUND\n"));
        return;
    }

    testData data = {{NAN, NAN, NAN}, {NAN, NAN}, 0, 0, ""};
    int scanned = 0;
    int test_count = 0;

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

        test_count++;

        if (scanned == 0) {
            int symbol = fgetc(fp);

            if (symbol != ']' && symbol != '[') {
                printf(RED("ERROR:") RED_CURSIVE(" BAD CHARACTERS IN TEST FILE\n"));
            }
        }
        else if (scanned < AMOUNT_OF_PARAMETERS) {
            printf(RED("ERROR:") RED_CURSIVE(" COULDN'T READ THE EXPECTED AMOUNT OF PARAMETERS\n"));
        }
        else {
            passedCount += testSolveSquare(&data);
        }
    } 
    
    if (passedCount == test_count) {
        printf ("##" GREEN("PASSED ALL %d TESTS"), test_count);
    }
    else {
        printf("##" GREEN("PASSED %d TESTS,") RED(" FAILED %d TESTS\n"), 
               passedCount, test_count - passedCount);
    }
}

int main()
{
    printf("##" YELLOW("STARTING TESTING SOLVE_SQUARE\n"));
    runTestSolveSquare();
}
