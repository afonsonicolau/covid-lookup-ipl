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
int mainMenu() {
    int optionChoosen;

    printf("\t**************************************************");
    printf("\n\t** \t\t\t\t\t\t**");
    printf("\n \t** \t\tCOVID Lookup System \t\t**");
    printf("\n\t** \t\t\t\t\t\t**");
    printf("\n\t**************************************************");

    printf("\n\n\tMembers Inserted: %d \t\tTests Scheduled: %d", 1, 1);
    printf("\n\tMembers Vaccinated: %d \t\tTests Performed: %d", 1, 1);

    printf("\n\n\t1. Member Options");
    printf("\n\t2. Vaccination Options");
    printf("\n\t3. Test Options");
    printf("\n\t4. Confinment Options");
    
    printf("\n\n\tOption: ");
    scanf("%d", &optionChoosen);

    return optionChoosen;
}

void program_menu() //Function that triggers the program menu
{
    char option;

    switch (option)
    {
    case '1': //Add member of the comunity
       
        break;
    case '2': //List members of the community

        break;
    case '3': //Register state of vaccination/lockdown
        break;

    case '4': //Schedule a test for covid-19 (Max 15 PCR TYPE)
        break;
    
    case '5': //List all the done tests and change the date (MAYBE)
        break;
    
    case '':
    default:
        break;
    }
}

// Main function
int main() {
    communityMember member[MAX_MEMBERS];
    
    mainMenu();

    return 0;
}

