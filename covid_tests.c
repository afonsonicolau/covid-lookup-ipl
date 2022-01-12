#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Files
#include "aux_functions.h"
#include "members.h"
#include "covid_tests.h"

diagnosticTest readTests() {
    diagnosticTest tests;

    tests.snsNumber = readInt("SNS number: ", SNSNUMBER_MIN, SNSNUMBER_MAX);
    tests.type = readInt("Test type (1 - PCR  2 - Antigen): ", MAX_FALSE, MAX_TRUE);
    tests.result = readInt("Result: (1- Positive  2- Negative 3- Undefined)", MAX_FALSE, MAX_TRUE);
    tests.timeTaken = readInt("Time taken: (in minutes)", MAX_FALSE, MAX_TRUE);
    tests.dateTaken = readDate();

    return tests;
}

int searchTests(diagnosticTest arrayMember[], int quantity, int snsNumber) {
    int i;
    int position = -1;

    for (i = 0; i < quantity; i++) {
        if (arrayMember[i].snsNumber == snsNumber) {
            position = i;
            i = quantity;
        }
    }

    return position;
}

diagnosticTest *createTests(diagnosticTest *vTest, int *number) {
    diagnosticTest *pTest, data;
    int pos;

    readFromMember(&data);
    pTest = vTest;
    pos = searchTests(vTest, *number, data.snsNumber);

    if (pos != -1) {
        printf("Test already done!");
    }
    else {
        vTest = realloc(vTest, (*number + 1) * sizeof(diagnosticTest));

        if (vTest == NULL) {
            printf("Error - Impossible to register a test!");
            vTest = pTest;
        }
        else {
            vTest[*number] = data;
            (*number)++;
        }
    }

    return vTest;
}

diagnosticTest *deleteTest(diagnosticTest *vTest, int *number) {
    diagnosticTest *pTest, data;
    int pos, i;

    pTest = vTest;

    if (*number != 0) {
        pos = searchTests(vTest, *number, number);
        if (pos == -1) {
            printf("This test doesn´t exist!");
        }
        else {
            for (i = 0; i < *number - 1; i++) {
                vTest[i] = vTest[i + 1];
            }
            vTest = realloc(vTest, (*number - 1) * sizeof(diagnosticTest));

            if (vTest == NULL && (*number - 1) != 0) {
                printf("Error on allocating the memory ");
                vTest = pTest;
            }
            (*number)--;
        }
    }

    return vTest;
}

void writeOnBin(diagnosticTest *vTest, int *number) {
    FILE *file;

    file = fopen("diagnosticTest.dat", "wb");

    if (file == NULL) {
        printf("Impossible to open the file");
    }
    else {
        fwrite(&number, sizeof(int), 1, file);
        fwrite(vTest, sizeof(diagnosticTest), number, file);
        fclose(file);
    }
}

void writeOnFile(diagnosticTest *vFunc, int number) {
    FILE *file;
    int i;
    file = fopen("diagnosticTest.txt", "w");

    if (file == NULL) {
        printf("Impossible to open the file");
    }
    else {
        fprintf(file, "Diagnostic Test =%d \n", number);
        for (i = 0; i < number; i++) {
            fprintf(file, "%d \t", vFunc[i].snsNumber);
            fprintf(file, "%d\n", vFunc[i].type);
            fprintf(file, "%d \t", vFunc[i].result);
            fprintf(file, "%d \t", vFunc[i].timeTaken);
        }
        fclose(file);
    }
}
