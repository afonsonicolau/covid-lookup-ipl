#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Headers
#include "members.h"
#include "aux_functions.h"
#include "covid_tests.h"
#include "vaccination_functions.h"
#include "confinment_functions.h"

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
        printf("\n\t4. General Statistics");
        printf("\n\t5. Return");

        optionChoosen = readInt("\n\n\tOption", 1, 4);
    } while (optionChoosen < 1 &&  optionChoosen > 4);

    switch (optionChoosen) {
        case 1: // Create Members
            createMember(arrayMember, &membersQuantity);
            system("cls");
            break;
        case 2: // List Members
            listMembers(arrayMember, membersQuantity);
            system("cls");
            break;
        case 3: // Update Member
            updateMember(arrayMember, membersQuantity);
            system("cls");
            break;
        case 4: // Show Statistics
            showStatistics(covidTests, arrayMember, membersQuantity, testsQuantity);
            system("cls");
            break;
        default:
            system("cls");
            break;
    }

    mainMenu(covidTests, arrayMember, membersQuantity, testsQuantity);
}

void testsMenu(diagnosticTest *covidTests, communityMember arrayMember[MAX_MEMBERS], int membersQuantity, int testsQuantity) {
    int optionChoosen;
    int snsNumber = 0;
    int scheduledTest = scheduledTests(covidTests, testsQuantity);
    int performedTest = performedTests(covidTests, testsQuantity);

    do {
        printf("\t**************************************************");
        printf("\n\t** \t\t\t\t\t\t**");
        printf("\n \t** \t\tCLS - Test Options \t\t**");
        printf("\n\t** \t\t\t\t\t\t**");
        printf("\n\t**************************************************");

        printf("\n\n\tTests Scheduled: %d", scheduledTest);
        printf("\n\tTests Performed: %d", performedTest);

        printf("\n\n\t1. Schedule Test");
        printf("\n\t2. List Tests");
        printf("\n\t3. Update Test Date");
        printf("\n\t4. Return");

        optionChoosen = readInt("\n\n\tOption", 1, 4);
    } while (optionChoosen < 1 &&  optionChoosen > 4);

    switch (optionChoosen) {
        case 1: // Create Test
            covidTests = createTests(covidTests, arrayMember, membersQuantity, &testsQuantity);
            system("cls");
            break;
        case 2: // List Tests
            //covidTests = readBin(covidTests, &testsQuantity);
            listTests(covidTests, testsQuantity);
            system("cls");
            break;
        case 3: // Update Testa Date
            updateTests(covidTests, arrayMember, membersQuantity, testsQuantity);
            system("cls");
            break;
        default:
            system("cls");
            break;
    }

    //writeOnBin(covidTests, testsQuantity);
    mainMenu(covidTests, arrayMember, membersQuantity, testsQuantity);
}

void vaccinationMenu(diagnosticTest *covidTests, communityMember arrayMember[MAX_MEMBERS], int membersQuantity, int testsQuantity) {
    int optionChoosen;
    int snsNumber = 0;
    int vaccinatedQuantity = vaccinatedMembers(arrayMember, membersQuantity);

    do {
        printf("\t**************************************************");
        printf("\n\t** \t\t\t\t\t\t**");
        printf("\n \t** \t\tCLS - Vaccination Options \t\t**");
        printf("\n\t** \t\t\t\t\t\t**");
        printf("\n\t**************************************************");

        printf("\n\tMembers Vaccinated: %d", vaccinatedQuantity);

        printf("\n\n\t1. Register Vaccination for Member (FIRST dose)");
        printf("\n\t2. Update Member Vaccination State (Remaining doses)");
        printf("\n\t3. Return");

        optionChoosen = readInt("\n\n\tOption", 1, 3);
    } while (optionChoosen < 1 &&  optionChoosen > 3);

    switch (optionChoosen) {
        case 1: // Register Vaccine
            registerVaccination(arrayMember, membersQuantity);
            system("cls");
            break;
        case 2: // Update Vaccine
            updateVaccination(arrayMember, membersQuantity);
            system("cls");
            break;
        default:
            system("cls");
            break;
    }

    mainMenu(covidTests, arrayMember, membersQuantity, testsQuantity);
}

void confinmentMenu(diagnosticTest *covidTests, communityMember arrayMember[MAX_MEMBERS], int membersQuantity, int testsQuantity) {
    int optionChoosen;
    int snsNumber = 0;
    int confinedQuantity = confinedMembers(arrayMember, membersQuantity);

    do {
        printf("\t**************************************************");
        printf("\n\t** \t\t\t\t\t\t**");
        printf("\n \t** \t\tCLS - Test Options \t\t**");
        printf("\n\t** \t\t\t\t\t\t**");
        printf("\n\t**************************************************");

        printf("\n\tMembers Confined: %d", confinedQuantity);

        printf("\n\n\t1. List Confinments");
        printf("\n\t2. Update Confinment State");
        printf("\n\t3. Return");

        optionChoosen = readInt("\n\n\tOption", 1, 3);
    } while (optionChoosen < 1 &&  optionChoosen > 3);

    switch (optionChoosen) {
        case 1: // List Confinments
            listConfinmentCases(arrayMember, membersQuantity);
            system("cls");
            break;
        case 2: // Update Confinment State
            updateConfinmentState(arrayMember, membersQuantity);
            system("cls");
            break;
        default:
            system("cls");
            break;
    }

    mainMenu(covidTests, arrayMember, membersQuantity, testsQuantity);
}

void redirectingMenu(diagnosticTest *covidTests, communityMember arrayMember[MAX_MEMBERS], int membersQuantity, int testsQuantity, int option) {
    system("cls");

    switch (option) {
        case 1: // Member Menu
            membersMenu(covidTests, arrayMember, membersQuantity, testsQuantity);
            break;
        case 2: // Vaccination Menu
            vaccinationMenu(covidTests, arrayMember, membersQuantity, testsQuantity);
            break;
        case 3: // Test Menu
            testsMenu(covidTests, arrayMember, membersQuantity, testsQuantity);
            break;
        case 4: // Confinment Menu
            confinmentMenu(covidTests, arrayMember, membersQuantity, testsQuantity);
            break;
        default:
            break;
    }
}

void mainMenu(diagnosticTest *covidTests, communityMember arrayMember[MAX_MEMBERS], int membersQuantity, int testsQuantity) {
    int optionChoosen;
    int vaccinatedQuantity = vaccinatedMembers(arrayMember, membersQuantity);
    int scheduledTest = scheduledTests(covidTests, testsQuantity);
    int performedTest = performedTests(covidTests, testsQuantity);


    do {
        printf("\t**************************************************");
        printf("\n\t** \t\t\t\t\t\t**");
        printf("\n \t** \t\tCOVID Lookup System \t\t**");
        printf("\n\t** \t\t\t\t\t\t**");
        printf("\n\t**************************************************");

        printf("\n\n\tMembers Created: %d \t\tTests Scheduled: %d", membersQuantity, scheduledTest);
        printf("\n\tMembers Vaccinated: %d \t\tTests Performed: %d", vaccinatedQuantity, performedTest);

        printf("\n\n\t1. Member Options");
        printf("\n\t2. Vaccination Options");
        printf("\n\t3. Test Options");
        printf("\n\t4. Confinment Options");
        printf("\n\t5. Exit");

        optionChoosen = readInt("\n\n\tOption", 1, 5);
    } while (optionChoosen < 1 &&  optionChoosen > 5);

    redirectingMenu(covidTests, arrayMember, membersQuantity, testsQuantity, optionChoosen);
}
