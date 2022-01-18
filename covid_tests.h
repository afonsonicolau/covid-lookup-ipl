#ifndef COVID_TESTS_H_INCLUDED
#define COVID_TESTS_H_INCLUDED

#include "aux_functions.h"

// Structures
typedef struct {
    int id;
    int snsNumber;
    int type;
    int result;
    int timeTaken;
    date dateTaken;
} diagnosticTest;

//Functions
diagnosticTest readTests();
int searchTests(diagnosticTest arrayMember[], int quantity, int snsNumber);
diagnosticTest *createTests(diagnosticTest *vTest, int *number);
diagnosticTest *deleteTest(diagnosticTest *vTest, int *number, int snsNumber);
void writeOnBin(diagnosticTest *vTest, int *number);
diagnosticTest *readBin(diagnosticTest *vTest, int *number);
void writeOnFile(diagnosticTest *vFunc, int number);
int searchBySNS(diagnosticTest arraytest[], int number, int snsNumber);

#endif