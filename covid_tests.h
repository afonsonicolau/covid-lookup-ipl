#ifndef COVID_TESTS_H_INCLUDED
#define COVID_TESTS_H_INCLUDED

// Headers
#include "aux_functions.h"
#include "members.h"

// Constants
#define MAX_TESTS 15
#define SNSNUMBER_MIN 111111111
#define SNSNUMBER_MAX 999999999


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
diagnosticTest getTestInfo();
int searchTests(diagnosticTest *covidTests, int quantity, int snsNumber);
diagnosticTest *createTests(diagnosticTest *covidTests, communityMember arrayMember[MAX_MEMBERS], int membersQuantity, int *testsQuantity);
void writeOnBin(diagnosticTest *covidTests, int number);
diagnosticTest *readBin(diagnosticTest *covidTests, int *number);
int scheduledTests(diagnosticTest *covidTests, int quantity);
int performedTests(diagnosticTest *covidTests, int quantity);
void listTests(diagnosticTest *covidTests, int quantity);
void updateTests(diagnosticTest *covidTests, communityMember arrayMember[MAX_MEMBERS], int membersQuantity, int testsQuantity);
void showStatistics(diagnosticTest *covidTests, communityMember arrayMember[MAX_MEMBERS], int membersQuantity, int testsQuantity);

#endif
