#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include "covid_tests.h"
#include "members.h"

// Functions
void testsMenu(diagnosticTest *covidTests, communityMember arrayMember[MAX_MEMBERS], int membersQuantity, int testsQuantity);
void membersMenu(diagnosticTest *covidTests, communityMember arrayMember[MAX_MEMBERS], int membersQuantity, int testsQuantity);
void vaccinationMenu(communityMember arrayMember[MAX_MEMBERS], int quantity);
void redirectingMenu(diagnosticTest *covidTests, communityMember arrayMember[MAX_MEMBERS], int membersQuantity, int testsQuantity, int option);
void mainMenu(diagnosticTest *covidTests, communityMember arrayMember[MAX_MEMBERS], int membersQuantity, int testsQuantity);

#endif
