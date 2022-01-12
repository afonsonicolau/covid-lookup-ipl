#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#include "menus.h"
#include "covid_tests.h"
#include "members.h"


int mainMenu() {
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

        printf("\n\n\tOption: ");
        scanf("%d", &optionChoosen);

    } while (optionChoosen < 1 &&  optionChoosen > 4);

    return optionChoosen;
}

void program_menu(int option) { // Function that triggers the program menu {


    switch (option) {
        case 1: // Member Options

            break;
        case 2: // Vaccination Options

            break;
        case 3: // Test Options
            break;

        case 4: // Confinment Options
            break;

        default:
            break;
    }
}
