#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Files & Headers
#include "aux_functions.h"
#include "menus.h"

// Members Header
#include "members.h"

communityMember getMemberInfo() {
    communityMember data;

    data.snsNumber = readInt("SNS Number", SNSNUMBER_MIN, SNSNUMBER_MAX);
    readString("Member Name", data.name, MAX_STRING);
    data.birthDate = readDate("Date of Birth");
    data.vaccinationState = readInt("Vaccination State (0 - No Vaccine || 1 - 1 Dose || 2 - 2 Dose || 3 - 3 Dose)", 0, 3);
    data.confinmentState = readInt("Confinment State (0 - Not Confined || 1 - Quarantine || 2 - P. Isolation)", 0, 2);
    data.memberRole = readInt("Member Role State (0 - Student || 1 - Teacher || 2 - Technician)", 0, 2);

    if (data.vaccinationState > 0) {
        data.lastVaccine = readDate("Last Vaccine Taken");
    }
    else {
        data.lastVaccine.year = 0;
        data.lastVaccine.month = 0;
        data.lastVaccine.day = 0;
    }

    return data;
}

int searchMember(communityMember arrayMember[MAX_MEMBERS], int quantity, int snsNumber) {
    int i = 0;
    int position = -1;

    for (; i < quantity; i++) {

        if (arrayMember[i].snsNumber == snsNumber) {
            position = i;
            i = quantity;
        }
    }

    return position;
}

void createMember(communityMember arrayMember[MAX_MEMBERS],int *quantity) {
    int position;
    communityMember infoMember;

    if (*quantity == MAX_MEMBERS) {
        printf("\n\tYou can´t create more community members!");
    }
    else {
        infoMember = getMemberInfo();

        position = searchMember(arrayMember, *quantity, infoMember.snsNumber);

        if (position == -1) {
            arrayMember[*quantity] = infoMember;
            (*quantity)++;

            printf("\n\tA new member was created, redirecting to main menu...\n\n");
        }
        else {
            printf("\n\tThis member is already registered, redirecting to main menu...\n\n");
        }
    }
}

void updateMember(communityMember arrayMember[MAX_MEMBERS],int quantity) {
    int position;
    communityMember infoMember;

    if (quantity <= 0) {
        printf("\n\tIts impossible to update members when they dont exist!");
    }
    else {
        infoMember = getMemberInfo();

        position = searchMember(arrayMember, quantity, infoMember.snsNumber);

        if (position != -1) {
            arrayMember[quantity] = infoMember;
            (quantity)++;

            printf("\n\tA new member was created, redirecting to main menu...\n\n");
        }
        else {
            printf("\n\tThis member is already registered, redirecting to main menu...\n\n");
        }
    }
}

void listMembers(communityMember arrayMember[MAX_MEMBERS], int quantity) {
    if(quantity == 0) {
        printf("\n\tThere is no members...\n");
        return;
    }

    int i = 0;
    printf("\n\tListing %d Members...\n", quantity);

    for (; i < quantity; i++) {
        printf("\n\tSNS Number: %d", arrayMember[i].snsNumber);
        printf("\n\tName: %s", arrayMember[i].name);
        printf("\n\tDate of Birth: %d/%d/%d", arrayMember[i].birthDate.day, arrayMember[i].birthDate.month, arrayMember[i].birthDate.year);

        // Reads memberRole value and associates it's description to it
        if (arrayMember[i].memberRole == 0) printf("\n\tRole: Student");
        else if (arrayMember[i].memberRole == 1) printf("\n\tRole: Teacher");
        else if (arrayMember[i].memberRole == 2) printf("\n\tRole: Technician");
        else printf("\n\tSomething went wrong, can't read member role.");

        // Get member vaccionation state and verify it's value in order to show correct result to user
        if (arrayMember[i].vaccinationState == 0) printf("\n\tThis member is NOT vaccinated");
        else if (arrayMember[i].vaccinationState == 1) printf("\n\tThis member has the FIRST vaccine dose");
        else if (arrayMember[i].vaccinationState == 2) printf("\n\tThis member has the SECOND vaccine dose");
        else if (arrayMember[i].vaccinationState == 3) printf("\n\tThis member has the THIRD vaccine dose");
        else printf("\n\tSomething went wrong, can't read member vaccination state.");

        // Get member confinment state and verify it's value in order to show correct result to user
        if (arrayMember[i].confinmentState == 0) printf("\n\tThis member is NOT confined or quaratined");
        else if (arrayMember[i].confinmentState == 1) printf("\n\tThis member IS quarantined");
        else if (arrayMember[i].confinmentState == 1) printf("\n\tThis members IS in p. isolation");
        else printf("\n\tSomething went wrong, can't read member confinment state.");
    }
}

// Get vaccinated members
int vaccinatedMembers(communityMember arrayMember[MAX_MEMBERS], int membersQuantity) {
    int i = 0;
    int vaccinatedQuantity = 0;

    for (; i < membersQuantity; i++) {
        // Checks if member has 1º, 2º or 3º vaccine dose
        if (arrayMember[i].vaccinationState > 0) {
            vaccinatedQuantity = vaccinatedQuantity + 1;
        }
    }

    return vaccinatedQuantity;
}
