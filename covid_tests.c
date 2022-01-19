#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Files
#include "aux_functions.h"
#include "covid_tests.h"
#include "menus.h"

diagnosticTest readTests() {
    diagnosticTest test;

    test.snsNumber = readInt("SNS Number", SNSNUMBER_MIN, SNSNUMBER_MAX);
    test.type = readInt("Test type (1 - PCR  || 2 - Antigen)", 1, 2);
    test.result = 1; /* 1 - Positive || 2 - Negative || 3 - Undefined */
    test.timeTaken = readTime("When was the test done");
    test.dateTaken = readDate("");

    return test;
}

int searchTests(diagnosticTest *covidTests, int quantity, int snsNumber) {
    int i;
    int position = -1;

    for (i = 0; i < quantity; i++) {
        if (covidTests[i].snsNumber == snsNumber) {
            position = i;
            i = quantity;
        }
    }

    return position;
}

diagnosticTest *createTests(diagnosticTest *covidTests, int *quantity) {
    diagnosticTest *pTest, data;
    int pos;

    pTest = covidTests;
    data = readTests();
    pos = searchTests(covidTests, *quantity, data.snsNumber);

    if (pos != -1) {
        printf("Test already done!");
    }
    else {
        covidTests = realloc(covidTests, (*quantity + 1) * sizeof(diagnosticTest));

        if (covidTests == NULL) {
            printf("Error - Impossible to register a test!");
            covidTests = pTest;
        }
        else {
            covidTests[*quantity] = data;
            (*quantity)++;
        }
    }

    return covidTests;
}

diagnosticTest *readBin(diagnosticTest *covidTests, int *number) {
    FILE *file;

    file = fopen("diagnosticTest.dat", "rb");

    if (file == NULL) {
        printf("Impossible to open the file!");
    }
    else {
        fread(&(*number), sizeof(int), 1, file);
        covidTests = realloc(covidTests, (*number) * sizeof(diagnosticTest));

        if (covidTests == NULL && *number != 0) {
            printf("Error allocating memory!");
            *number = 0;
        }
        else {
            fread(covidTests, sizeof(diagnosticTest), *number, file);
        }
        fclose(file);
    }

    return covidTests;
}

void writeOnFile(diagnosticTest *covidTests, int number) {
    FILE *file;
    int i;
    file = fopen("diagnosticTest.txt", "w");

    if (file == NULL) {
        printf("Impossible to open the file");
    }
    else {
        fprintf(file, "Diagnostic Test =%d \n", number);
        for (i = 0; i < number; i++) {
            fprintf(file, "%d \t", covidTests[i].snsNumber);
            fprintf(file, "%d\n", covidTests[i].type);
            fprintf(file, "%d \t", covidTests[i].result);
            fprintf(file, "%d:%d \t", covidTests[i].timeTaken.hour, covidTests[i].timeTaken.minute);
        }

        fclose(file);
    }
}
