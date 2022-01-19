#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Files & Headers
#include "members.h"
#include "aux_functions.h"
#include "covid_tests.h"

// Menus Headers
#include "menus.h"

void membersMenu(diagnosticTest *covidTests, communityMember arrayMember[MAX_MEMBERS], int membersQuantity, int testsQuantity) {
    int optionChoosen;
    int vaccinatedQuantity = vaccinatedMembers(arrayMember, membersQuantity);

    do {
        printf("\t**************************************************");
        printf("\n\t** \t\t\t\t\t\t**");
        printf("\n \t** \t\tCLS - Member Options \t\t**");
        printf("\n\t** \t\t\t\t\t\t**");
        printf("\n\t**************************************************");

        printf("\n\n\tMembers Created: %d", membersQuantity);
        printf("\n\tMembers Vaccinated: %d", vaccinatedQuantity);


        printf("\n\n\t1. Create Member");
        printf("\n\t2. List Members");
        printf("\n\t3. Update Member");

        optionChoosen = readInt("\n\n\tOption", 1, 3);
    } while (optionChoosen < 1 &&  optionChoosen > 3);

    switch (optionChoosen) {
        case 1: // Create Members
            createMember(arrayMember, &membersQuantity);
            break;
        case 2: // List Members
            listMembers(arrayMember, membersQuantity);
            break;
        case 3: // Update Member

            break;

        default:
            break;
    }

    mainMenu(covidTests, arrayMember, membersQuantity, testsQuantity);
}

void testsMenu(diagnosticTest *covidTests, communityMember arrayMember[MAX_MEMBERS], int membersQuantity, int testsQuantity) {
    int optionChoosen;
    int snsNumber = 0;

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

    switch (optionChoosen) {
        case 1: // Create Test
            createTests(covidTests, &testsQuantity);
            break;
        case 2: // List Tests
            snsNumber = readInt("SNS Number", SNSNUMBER_MIN, SNSNUMBER_MAX);
            searchTests(covidTests, testsQuantity, snsNumber);
            break;
        case 3: // Update Testa Date

            break;

        default:
            break;
    }

    mainMenu(covidTests, arrayMember, membersQuantity, testsQuantity);
}

void redirectingMenu(diagnosticTest *covidTests, communityMember arrayMember[MAX_MEMBERS], int membersQuantity, int testsQuantity, int option) {
    switch (option) {
        case 1: // Member Menu
            membersMenu(covidTests, arrayMember, membersQuantity, testsQuantity);
            break;
        case 2: // Vaccination Menu
            printf("Ainda nao");
            break;
        case 3: // Test Menu
            testsMenu(covidTests, arrayMember, membersQuantity, testsQuantity);
            break;
        case 4: // Confinment Menu
            printf("Ainda nao");
            break;

        default:
            break;
    }
}

void mainMenu(diagnosticTest *covidTests, communityMember arrayMember[MAX_MEMBERS], int membersQuantity, int testsQuantity) {
    int optionChoosen;
    int vaccinatedQuantity = vaccinatedMembers(arrayMember, membersQuantity);
    int testsScheduled = 0;
    int testsPerformed = 0;

    do {
        printf("\t**************************************************");
        printf("\n\t** \t\t\t\t\t\t**");
        printf("\n \t** \t\tCOVID Lookup System \t\t**");
        printf("\n\t** \t\t\t\t\t\t**");
        printf("\n\t**************************************************");

        printf("\n\n\tMembers Created: %d \t\tTests Scheduled: %d", membersQuantity, testsScheduled);
        printf("\n\tMembers Vaccinated: %d \t\tTests Performed: %d", vaccinatedQuantity, testsPerformed);

        printf("\n\n\t1. Member Options");
        printf("\n\t2. Vaccination Options");
        printf("\n\t3. Test Options");
        printf("\n\t4. Confinment Options");

        optionChoosen = readInt("\n\n\tOption", 1, 4);
    } while (optionChoosen < 1 &&  optionChoosen > 4);

    redirectingMenu(covidTests, arrayMember, membersQuantity, testsQuantity, optionChoosen);
}
