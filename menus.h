#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include "menus.c"

// Functions
void programMenu(diagnosticTest *arrayTest, int quantity, int option);
void testsPaths(diagnosticTest *arrayTest, int quantity, int option);
void mainMenu(communityMember arrayMember[MAX_MEMBERS], diagnosticTest *arrayTest, int quantity);
void testsMenu(diagnosticTest *arrayTest, int quantity);

#endif