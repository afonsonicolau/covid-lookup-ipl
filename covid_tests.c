#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Files
#include "aux_functions.h"
#include "members.h"
#include "covid_tests.h"

diagnosticTest readTests()
{
    diagnosticTest tests;

    tests.snsNumber = readInt("SNS number: ", SNSNUMBER_MIN, SNSNUMBER_MAX);
    tests.type = readInt("Test type (1 - PCR  2 - Antigen): ", MAX_FALSE, MAX_TRUE);
    tests.result = readInt("Result: (1- Positive  2- Negative 3- Undefined)", MAX_FALSE, MAX_TRUE);
    tests.timeTaken = readInt("Time taken: (in minutes)", MAX_FALSE, MAX_TRUE);
    tests.dateTaken = readDate();

    return tests;
}

int searchTests(diagnosticTest arraytest[], int quantity, int snsNumber)
{
    int i;
    int position = -1;

    for (i = 0; i < quantity; i++)
    {
        if (arraytest[i].snsNumber == snsNumber)
        {
            position = i;
            i = quantity;
        }
    }

    return position;
}

diagnosticTest *createTests(diagnosticTest *arraytest, int *number)
{
    diagnosticTest *pTest, data;
    int pos, snsNumber;

    pTest = arraytest;
    data = readTests();
    pos = searchTests(arraytest, *number, data.snsNumber);

    if (pos != -1)
    {
        printf("Test already done!");
    }
    else
    {
        arraytest = realloc(arraytest, (*number + 1) * sizeof(diagnosticTest));

        if (arraytest == NULL)
        {
            printf("Error - Impossible to register a test!");
            arraytest = pTest;
        }
        else
        {
            arraytest[*number] = data;
            (*number)++;
        }
    }

    return arraytest;
}

diagnosticTest *readBin(diagnosticTest *arraytest, int *number)
{
    FILE *file;

    file = fopen("diagnosticTest.dat", "rb");

    if (file == NULL)
    {
        printf("Impossible to open the file!");
    }
    else
    {
        fread(&(*number), sizeof(int), 1, file);
        arraytest = realloc(arraytest, (*number) * sizeof(diagnosticTest));

        if (arraytest == NULL && *number != 0)
        {
            printf("Error allocating memory!");
            *number = 0;
        }
        else
        {
            fread(arraytest, sizeof(diagnosticTest), *number, file);
        }
        fclose(file);
    }
    return arraytest;
}

int searchBySNS(diagnosticTest arraytest[], int number, int snsNumber)
{
    int i, pos;
    pos = -1;

    for (i = 0; i < number; i++)
    {
        if (arraytest[i].snsNumber == snsNumber)
        {
            pos = i;
            i = number;
        }
    }
    return pos;
}

void writeOnFile(diagnosticTest *arraytest, int number)
{
    FILE *file;
    int i;
    file = fopen("diagnosticTest.txt", "w");

    if (file == NULL)
    {
        printf("Impossible to open the file");
    }
    else
    {
        fprintf(file, "Diagnostic Test =%d \n", number);
        for (i = 0; i < number; i++)
        {
            fprintf(file, "%d \t", arraytest[i].snsNumber);
            fprintf(file, "%d\n", arraytest[i].type);
            fprintf(file, "%d \t", arraytest[i].result);
            fprintf(file, "%d \t", arraytest[i].timeTaken);
        }
        fclose(file);
    }
}
