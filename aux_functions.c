#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Auxiliary Functions Header
#include "aux_functions.h"

void cleanBuffer(void) {
    char char_check;

    do {
        char_check = getchar();
    } while (char_check != '\n' && char_check != EOF);
}

int readInt(char message[MAX_STRING], int min, int max) {
    int number, control;

    do {
        printf("\t%s (%d to %d): ", message, min, max);
        control = scanf("%d", &number);
        cleanBuffer();

        if (control == 0){
            printf("You must insert an integer \n");
        }
        else {
            if (number < min || number > max) {
                printf("Invalid number, insert again...: \n");
            }
        }
    } while (number < min || number > max || control == 0);

    return number;
}

float readFloat(char message[MAX_STRING], float min, float max) {
    float number;
    int control;

    do {
        printf("\t%s (%.2f to %.2f): ", message, min, max);
        control = scanf("%f", &number);
        cleanBuffer();

        if (control == 0) {
            printf("You must insert a float number: \n");
        }
        else {
            if (number < min || number > max) {
                printf("Invalid number, try again: \n");
            }
        }
    } while (number < min || number > max || control == 0);

    return number;
}

void readString(char message[MAX_STRING], char arrayChar[MAX_STRING], int maxChar) {
    int sizeString;

    do {
        printf("\t%s: ", message);
        fgets(arrayChar, maxChar, stdin);

        sizeString = strlen(arrayChar);

        if (sizeString == 1) {
            printf("Please, insert some information!\n\n");
        }
    } while (sizeString == 1);

    if (arrayChar[sizeString - 1] != '\n') {
        cleanBuffer();
    }
    else {
        arrayChar[sizeString - 1] = '\0';
    }
}

date readDate(void) {
    date date_read;
    int maxDaysMonth;

    date_read.year = readInt("Insert a year", 2020, 2021);
    date_read.month = readInt("Insert a month", 1, 12);

    switch (date_read.month) {
        case 2:
            if ((date_read.year % 400 == 0) || (date_read.year % 4 == 0 && date_read.year % 100 != 0)) {
                maxDaysMonth = 29;
            }
            else {
                maxDaysMonth = 28;
            }
        case 4:
        case 6:
        case 9:
        case 11:
            maxDaysMonth = 30;
            break;
        default:
            maxDaysMonth = 31;
    }

    date_read.day = readInt("Insert a day", 1, maxDaysMonth);
    
    return date_read;
}
