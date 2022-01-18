#ifndef MEMBERS_H_INCLUDED
#define MEMBERS_H_INCLUDED

// Constants
#define MAX_MEMBERS 200
#define MAX_STRING 50

#define MAX_TRUE 1
#define MAX_FALSE 0

#define SNSNUMBER_MIN 0
#define SNSNUMBER_MAX 999999999

#include "aux_functions.h"

// Structures
typedef struct {
    int snsNumber;
    char name[50];
    date birthDate;
    int memberRole;
    int confinmentState;
    int vaccinationState;
    date lastVaccine;
} communityMember;


// Functions
int searchMember(communityMember arrayMember[MAX_MEMBERS], int quantity, int number);
communityMember readFromMember();
void createMember(communityMember arrayMember[MAX_MEMBERS], int quantity);
int searchMember(communityMember arrayMember[MAX_MEMBERS], int quantity, int number);

#endif