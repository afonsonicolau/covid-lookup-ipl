#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Headers
#include "menus.h"
#include "covid_tests.h"
#include "members.h"

// Main function
int main() {
    int membersQuantity = 0;
    int testsQuantity = 0;
    communityMember arrayMember[MAX_MEMBERS];
    diagnosticTest *covidTests = NULL;

    // Call to main menu
    mainMenu(covidTests, arrayMember, membersQuantity, testsQuantity);

    free(covidTests);

    return 0;
}
