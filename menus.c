#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Files
#include "members.h"
#include "members.c"
#include "covid_tests.h"

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

void memberMenu(communityMember arrayMember[MAX_MEMBERS], int quantity) {
    int optionChoosen;

    do {
        printf("\t**************************************************");
        printf("\n\t** \t\t\t\t\t\t**");
        printf("\n \t** \t\tCLS - Member Options \t\t**");
        printf("\n\t** \t\t\t\t\t\t**");
        printf("\n\t**************************************************");

        printf("\n\n\tMembers Inserted: %d \t\tTests Scheduled: %d", 1, 1);
        printf("\n\tMembers Vaccinated: %d \t\tTests Performed: %d", 1, 1);

        printf("\n\n\t1. Create Community Member");
        printf("\n\t2. List Community Members ");
        printf("\n\t3. Update Community Member");

        optionChoosen = readInt("\n\n\tOption", 1, 3);
    } while (optionChoosen < 1 &&  optionChoosen > 3);

    memberPaths(arrayMember, quantity, optionChoosen);
}

void programMenu(communityMember arrayMember[MAX_MEMBERS], int quantity, int option) {
    switch (option) {
        case 1: // Member Menu
            memberMenu(arrayMember, quantity);
            break;
        case 2: // Vaccination Menu

            break;
        case 3: // Test Menu
            break;

        case 4: // Confinment Menu
            break;

        default:
            break;
    }
}

void memberPaths(communityMember arrayMember[MAX_MEMBERS], int quantity, int option) {
    switch (option) {
        case 1: // Create Member 
            createMember(arrayMember, quantity);
            break;
        case 2: // List Member 
            //listMembers();
            break;
        case 3: // Update Member 
            
            break;

        default:
            break;
    }
};
