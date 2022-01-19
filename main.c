#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Headers
#include "members.h"
#include "aux_functions.h"
#include "covid_tests.h"
#include "menus.h"

// Main function
int main(){

    int quantity = 0;
    communityMember members[MAX_MEMBERS];
    diagnosticTest *tests = NULL;

    mainMenu(tests, quantity);

    free(tests);
    return 0;
}
