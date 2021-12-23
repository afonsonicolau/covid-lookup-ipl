#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Constants
#define MAX_MEMBERS 200

// Structures
typedef struct {
    int day;
    int month;
    int year;
} date;

typedef struct {
    int hour;
    int minute;
} time;

typedef struct {
    int snsNumber;
    char name[50];
    date birthDate;
    int memberRole;
    int confinmentState;
    int vaccinationState;
    date lastVaccine;
} communityMember;

typedef struct {
    int id;
    int snsNumber;
    int type;
    int result;
    int duration;
    time timeTaken;
    date dateTaken;
} diagnosticTest;

// Functions

void switch_menu(){
    char option;

    switch (option)
    {
    case 'I': //Add member of the comunity
       
        break;
    case 'L': //List members of the community

        break;
    
    default:
        break;
    }
}

// Main function
int main() {
    communityMember member[MAX_MEMBERS];

    return 0;
}
