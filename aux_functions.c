#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Aux functions header
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
        if (strcmp(message, "\tInsert a day") == 0) {
            printf("\t%s (%d to %d): ", message, min, max);
        }
        else {
            printf("\t%s: ", message);
        }

        control = scanf("%d", &number);
        cleanBuffer();

        if (control == 0){
            printf("\n\tYou must insert an integer \n");
        }
        else {
            if (number < min || number > max) {
                printf("\n\tInvalid number, insert again...: \n");
            }
        }
    } while (number < min || number > max || control == 0);

    return number;
}

float readFloat(char message[MAX_STRING], float min, float max) {
    float number;
    int control;

    do {
        printf("\t%s:", message);
        control = scanf("%f", &number);
        cleanBuffer();

        if (control == 0) {
            printf("\n\tYou must insert a float number: \n");
        }
        else {
            if (number < min || number > max) {
                printf("\n\tInvalid number, try again: \n");
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
            printf("\tPlease insert some information!\n\n");
        }
    } while (sizeString == 1);

    if (arrayChar[sizeString - 1] != '\n') {
        cleanBuffer();
    }
    else {
        arrayChar[sizeString - 1] = '\0';
    }
}

date readDate(char message[MAX_STRING]) {
    date date_read;
    int maxDaysMonth;

    printf("\t%s:\n", message);

    if (strcmp(message, "Date of Birth") == 0) {
        date_read.year = readInt("\tInsert a year (1950 or 2004)", 1950, 2004);
    }
    else {
        date_read.year = readInt("\tInsert a year (2020 or 2021)", 2020, 2021);
    }

    date_read.month = readInt("\tInsert a month (1 to 12)", 1, 12);

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

    date_read.day = readInt("\tInsert a day", 1, maxDaysMonth);

    return date_read;
}

time readTime(char message[MAX_STRING]) {
    time time_read;

    printf("\t%s:\n", message);

    time_read.hour = readInt("\tInsert an hour (1 to 24)", 1, 24);
    time_read.minute = readInt("\tInsert a minute (0 to 60)", 0, 60);

    return time_read;
}
