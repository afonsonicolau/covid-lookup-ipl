#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Files & Headers
#include "menus.c"
#include "menus.h"
#include "members.h"

// Main function
int main() {
    int quantity = 0;
    communityMember members[MAX_MEMBERS];

    mainMenu(members, quantity);

    return 0;
}
