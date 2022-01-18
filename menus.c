#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Files & Headers
#include "members.h"
#include "members.c"

// Menus Headers
#include "menus.h"

void mainMenu(communityMember arrayMember[MAX_MEMBERS], int quantity) {
    int optionChoosen;

    do {
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

        optionChoosen = readInt("\n\n\tOption", 1, 4);
    } while (optionChoosen < 1 &&  optionChoosen > 4);

    programMenu(arrayMember, quantity, optionChoosen);
}

void testsMenu(diagnosticTest *arrayTest, int quantity) {
    int optionChoosen;

    do {
        printf("\t**************************************************");
        printf("\n\t** \t\t\t\t\t\t**");
        printf("\n \t** \t\tCLS - Test Options \t\t**");
        printf("\n\t** \t\t\t\t\t\t**");
        printf("\n\t**************************************************");

        printf("\n\n\tTests Scheduled: %d", 1);
        printf("\n\tTests Performed: %d", 1);

        printf("\n\n\t1. Schedule Test");
        printf("\n\t2. List Tests");
        printf("\n\t3. Update Test Date");

        optionChoosen = readInt("\n\n\tOption", 1, 3);
    } while (optionChoosen < 1 &&  optionChoosen > 3);

    memberPaths(arrayTest, quantity, optionChoosen);
}

void programMenu(diagnosticTest *arrayTest, int quantity, int option) {
    switch (option) {
        case 1: // Member Menu
            break;
        case 2: // Vaccination Menu
            break;
        case 3: // Test Menu
            testsMenu(arrayTest, quantity);
            break;
        case 4: // Confinment Menu
            break;

        default:
            break;
    }
}

void testPaths(diagnosticTest *arrayTest, int quantity, int option) {
    switch (option) {
        case 1: // Create Member 
            createTests(arrayTest, &quantity);
            break;
        case 2: // List Member 
            int snsNumber = readInt("SNS Number", SNSNUMBER_MIN, SNSNUMBER_MAX);
            searchBySNS(arrayTest, quantity, snsNumber);
            break;
        case 3: // Update Member 
            
            break;

        default:
            break;
    }
}
