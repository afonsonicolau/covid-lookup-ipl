#ifndef COVID_TESTS_H_INCLUDED
#define COVID_TESTS_H_INCLUDED

#define MAX_TESTS 15

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
int searchTests(diagnosticTest *covidTests, int quantity, int snsNumber);
diagnosticTest *createTests(diagnosticTest *covidTests, int *number);
void writeOnBin(diagnosticTest *covidTests, int *number);
diagnosticTest *readBin(diagnosticTest *covidTests, int *number);
void writeOnFile(diagnosticTest *covidTests, int number);
int searchBySNS(diagnosticTest *covidTests, int number, int snsNumber);

#endif
