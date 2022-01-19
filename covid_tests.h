#ifndef COVID_TESTS_H_INCLUDED
#define COVID_TESTS_H_INCLUDED

#include "aux_functions.h"

// Structures
typedef struct {
    int id;
    int snsNumber;
    int type;
    int result;
    time timeTaken;
    date dateTaken;
} diagnosticTest;

//Functions
diagnosticTest readTests();
int searchTests(diagnosticTest *arraytest, int quantity, int snsNumber);
diagnosticTest *createTests(diagnosticTest *arraytest, int *number);
void writeOnBin(diagnosticTest *arraytest, int *number);
diagnosticTest *readBin(diagnosticTest *arraytest, int *number);
void writeOnFile(diagnosticTest *arraytest, int number);
int searchBySNS(diagnosticTest *arraytest, int number, int snsNumber);

#endif
