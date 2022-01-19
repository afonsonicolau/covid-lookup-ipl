#ifndef MEMBERS_H_INCLUDED
#define MEMBERS_H_INCLUDED

// Headers
#include "aux_functions.h"

// Constants
#define MAX_MEMBERS 200
#define MAX_STRING 50

#define MAX_TRUE 1
#define MAX_FALSE 0

#define SNSNUMBER_MIN 111111111
#define SNSNUMBER_MAX 999999999

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
communityMember readNewMemberInfo();
int searchMember(communityMember arrayMember[MAX_MEMBERS], int quantity, int number);
void createMember(communityMember arrayMember[MAX_MEMBERS], int *quantity);
void listMembers(communityMember arrayMember[MAX_MEMBERS], int quantity);

#endif
