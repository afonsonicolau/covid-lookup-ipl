#ifndef COVID_TESTS_H_INCLUDED
#define COVID_TESTS_H_INCLUDED

#define MAX_TESTS 15
#define SNSNUMBER_MIN 111111111
#define SNSNUMBER_MAX 999999999


#include "aux_functions.h"
#include "members.h"


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
void writeOnBin(diagnosticTest *covidTests, int number);
diagnosticTest *readBin(diagnosticTest *covidTests, int *number);
int searchBySNS(communityMember arrayMember[MAX_MEMBERS] , int quantity, int snsNumber);
int scheduledTests(diagnosticTest *covidTests, int quantity);
int performedTests(diagnosticTest *covidTests, int quantity);
void listTests(diagnosticTest *covidTests, int quantity);
void updateTests(diagnosticTest *covidTests, communityMember arrayMember[MAX_MEMBERS], int membersQuantity, int testsQuantity);


#endif
