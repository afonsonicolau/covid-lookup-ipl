#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include "aux_functions.h"
#include "covid_tests.h"
#include "members.h"

// Functions
void programMenu(diagnosticTest *arrayTest, int quantity, int option);
void testsPaths(diagnosticTest *arrayTest, int quantity, int option);
void mainMenu(diagnosticTest *arrayTest, int quantity);
void testsMenu(diagnosticTest *arrayTest, int quantity);

#endif
