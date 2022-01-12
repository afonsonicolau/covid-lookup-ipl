#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

// Headers
#include "members.h"
#include "covid_tests.h"
#include "menus.c"

// Functions
void mainMenu(communityMember arrayMember[MAX_MEMBERS], int quantity);
void programMenu(communityMember arrayMember[MAX_MEMBERS], int quantity, int option);
void memberMenu(communityMember arrayMember[MAX_MEMBERS], int quantity);
void memberPaths(communityMember arrayMember[MAX_MEMBERS], int quantity, int option);

#endif