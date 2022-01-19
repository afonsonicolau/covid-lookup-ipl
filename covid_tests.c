#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Files
#include "aux_functions.h"
#include "covid_tests.h"
#include "menus.h"
#include "members.h"

diagnosticTest getTestInfo() {
    diagnosticTest test;

    test.id = rand();
    test.type = readInt("Test type (1 - PCR  || 2 - Antigen)", 1, 2);
    test.result = 0; /* 0 - No Result || 1 - Positive || 2 - Negative || 3 - Undefined */
    test.timeTaken = readTime("Whats the time the test will be performed");
    test.dateTaken = readDate("To when should the test be scheduled");

    return test;
}

// Search a test by associated SNS Number
int searchTests(diagnosticTest covidTests[], int quantity, int snsNumber) {
    int i;
    int position = -1;

    if (snsNumber == 0) {
        snsNumber = readInt("\n\tSNS Number", SNSNUMBER_MIN, SNSNUMBER_MAX);
    }

    for (i = 0; i < quantity; i++) {
        if (covidTests[i].snsNumber == snsNumber) {
            position = i;
        }
    }

    return position;
}

diagnosticTest *createTests(diagnosticTest *covidTests, communityMember arrayMember[MAX_MEMBERS], int membersQuantity, int *testsQuantity) {
    diagnosticTest newData;
    int pos;

    newData.snsNumber = readInt("SNS Number", SNSNUMBER_MIN, SNSNUMBER_MAX);
    pos = searchMember(arrayMember, membersQuantity, newData.snsNumber);

    if (pos == -1) {
        printf("\n\tMember doesnt exist...");
        pressToRedirect();
        return;
    }

    diagnosticTest *testBackup;

    testBackup = covidTests;
    newData = getTestInfo();

    covidTests = realloc(covidTests, (*testsQuantity + 1) * sizeof(diagnosticTest));

    if (covidTests == NULL) {
        printf("Error - Impossible to register a test!");
        covidTests = testBackup;
    }
    else {
        covidTests[*testsQuantity] = newData;
        (*testsQuantity)++;
        printf("Test was scheduled to %d/%d/%d, at %d:%d.",  newData.dateTaken.day, newData.dateTaken.month, newData.dateTaken.year,
                                                             newData.timeTaken.hour, newData.timeTaken.minute);
    }

    pressToRedirect();

    return covidTests;
}

void listTests(diagnosticTest *covidTests, int quantity) {
    // Checks if any test exists
    if(quantity == 0) {
        printf("\n\tThere is no tests...\n");

        pressToRedirect();

        return;
    }

    int i = 0;
    printf("\n\tListing %d Tests...\n", quantity);

    for (; i < quantity; i++) {
        printf("\n\tTest Designation: %d", covidTests[i].id);
        printf("\n\tSNS Number: %d", covidTests[i].snsNumber);
        // Gets type of test
        if (covidTests[i].type == 1) printf("\n\tType: PCR");
        else if (covidTests[i].type == 2) printf("\n\tType: Antigen");
        else printf("\n\tSomething went wrong, can't read test type.");

        printf("\n\tDate Taken: %d/%d/%d", covidTests[i].dateTaken.day, covidTests[i].dateTaken.month, covidTests[i].dateTaken.year);
        printf("\n\tTime Taken: %d:%d", covidTests[i].timeTaken.hour, covidTests[i].timeTaken.minute);

        // Gets test result
        if (covidTests[i].result == 0) printf("\n\tResult: Not yet performed");
        else if (covidTests[i].result == 1) printf("\n\tResult: Positive");
        else if (covidTests[i].result == 2) printf("\n\tResult: Negative");
        else if (covidTests[i].result == 3) printf("\n\tResult: Undefined");
        else printf("\n\tSomething went wrong, can't read test result.");

    }

    pressToRedirect();
}

void updateTests(diagnosticTest *covidTests, communityMember arrayMember[MAX_MEMBERS], int membersQuantity, int testsQuantity) {
    int memberExists = 0;
    memberExists = searchMember(arrayMember, membersQuantity, 0);

    // Cheks if member exists, if it doesn't it returns to main menu after a key is pressed
    if(memberExists == -1) {
        printf("\n\tThere are no members with given SNS Number");
        pressToRedirect();
        return;
    }

    int position;
    int testExists = 0;

    testExists = searchTests(covidTests, testsQuantity, 0);

    if(testExists == -1) {
        printf("\n\tThere are no test scheduled with given SNS Number");
        pressToRedirect();
    }
    else {
        covidTests[testExists].dateTaken = readDate("Update the test date");
        printf("\n\tDate was sucessfully changed!");
    }
}

diagnosticTest *readBin(diagnosticTest *covidTests, int *number) {
    FILE *file;
    int quantity_info, error;

    file = fopen("diagnosticTest.dat", "rb");

    if (file == NULL) {
        printf("\n\nImpossible to open the file!\n");
    }
     else
    {
        quantity_info = fread(&(*number), sizeof(int), 1, file);
        if (quantity_info != 1)
        {
            printf("Error!! We cant read the file");
            *number = 0;
        }
        else
        {
            covidTests = realloc(covidTests, *(number) *sizeof(diagnosticTest));
            if(covidTests == NULL)
            {
                printf("Error! We were not able to allocate memory");
                error=1;
            }
            else
            {
                quantity_info = fread(covidTests, sizeof(diagnosticTest), *number, file);
                if(quantity_info != *number)
                {
                    printf("Error!! We cant read the file");
                    *number= 0;
                }
            }
        }
        fclose(file);
    }

    if(error == 1){
        covidTests = NULL;
        free(covidTests);
        *number = 0;
    }

    return covidTests;
}

void writeOnBin(diagnosticTest *covidTests, int quantity) {
    FILE *file;
    file = fopen("diagnosticTest.data", "wb");

    if (file == NULL) {
        printf("Impossible to open the file\t");
    }
    else {

        fwrite(&quantity, sizeof(int), 1, file);
        fwrite(covidTests, sizeof(diagnosticTest), quantity, file);
        fclose(file);
    }
}

int scheduledTests(diagnosticTest *covidTests, int quantity) {
    int i = 0;
    int scheduledTests = 0;

    for (; i < quantity; i++) {
        if (covidTests[i].result == 0) {
            scheduledTests++;
        }
    }

    return scheduledTests;
}


int performedTests(diagnosticTest *covidTests, int quantity) {
    int i = 0;
    int performedTests = 0;

    for (; i < quantity; i++) {
        if (covidTests[i].result > 0) {
            performedTests++;
        }
    }

    return performedTests;
}
