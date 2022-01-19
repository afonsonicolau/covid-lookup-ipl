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
    data.memberRole = readInt("Member Role (0 - Student || 1 - Teacher || 2 - Technician)", 0, 2);

    data.vaccinationState = 0;
    data.confinmentState = 0;
    data.lastVaccine.year = 0;
    data.lastVaccine.month = 0;
    data.lastVaccine.day = 0;

    return data;
}

int searchMember(communityMember arrayMember[MAX_MEMBERS], int quantity, int snsNumber) {
    int i = 0;
    int position = -1;

    if (snsNumber == 0) {
        snsNumber = readInt("\n\tSNS Number", SNSNUMBER_MIN, SNSNUMBER_MAX);
    }

    for (; i < quantity; i++) {
        if (arrayMember[i].snsNumber == snsNumber) {
            position = i;
            i = quantity;
        }
    }

    return position;
}

void createMember(communityMember arrayMember[MAX_MEMBERS],int *quantity) {
    if (*quantity == MAX_MEMBERS) {
        printf("\n\tYou can´t create more community members!");
    }
    else {
        int position;
        communityMember infoMember;

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

void updateMember(communityMember arrayMember[MAX_MEMBERS], int membersQuantity) {
    if (membersQuantity <= 0) {
        printf("\n\tIts impossible to update members when they dont exist!");
    }
    else {
        int position = searchMember(arrayMember, membersQuantity, 0);

        if (position != -1) {
            printf("\n\tEditing %s:\n", arrayMember[position].name);
            arrayMember[position].memberRole = readInt("New Member Role (0 - Student || 1 - Teacher || 2 - Technician)", 0, 2);
            arrayMember[position].birthDate = readDate("Date of Birth");

            printf("\n\tMember data was updated...\n\n");
        }
        else {
            printf("\n\tThis member doesnt exist...\n\n");
        }
    }

    pressToRedirect();
}

void listMembers(communityMember arrayMember[MAX_MEMBERS], int quantity) {
    if (quantity <= 0) {
        printf("\n\tIts impossible to update members when they dont exist!");
        pressToRedirect();
        return;
    }

    int i = 0;
    printf("\n\tListing %d Members...\n", quantity);

    for (; i < quantity; i++) {
        printf("\n\tSNS Number: %d", arrayMember[i].snsNumber);
        printf("\n\tName: %s", arrayMember[i].name);
        printf("\n\tDate of Birth: %d/%d/%d", arrayMember[i].birthDate.day, arrayMember[i].birthDate.month, arrayMember[i].birthDate.year);

        // Reads memberRole value and associates it's description to it
        switch (arrayMember[i].memberRole) {
            case 0:
                printf("\n\tRole: Student");
                break;
            case 1:
                printf("\n\tRole: Teacher");
                break;
            case 2:
                printf("\n\tRole: Technician");
                break;
            default:
                printf("\n\tSomething went wrong, can't read member role.");
                break;
        }

        // Get member vaccionation state and verify it's value in order to show correct result to user
        if (arrayMember[i].vaccinationState == 0) {
            printf("\n\tThis member is NOT vaccinated");
        }
        else {
            printf("\n\tThis member has the %d vaccine dose", arrayMember[i].vaccinationState);
        }

        // Get member confinment state and verify it's value in order to show correct result to user
         switch (arrayMember[i].confinmentState) {
            case 0:
                printf("\n\tThis members is NOT quarantine/p. isolation");
                break;
            case 1:
                printf("\n\tThis member IS quarantined");
                break;
            case 2:
                printf("\n\tThis members IS in p. isolation");
                break;
            default:
                printf("\n\tSomething went wrong, can't read member confinment state.");
                break;
        }
    }
}

// Get vaccinated members
int vaccinatedMembers(communityMember arrayMember[MAX_MEMBERS], int membersQuantity) {
    int i = 0;
    int vaccinatedQuantity = 0;

    for (; i < membersQuantity; i++) {
        // Checks if member has 1º, 2º or 3º vaccine dose
        if (arrayMember[i].vaccinationState > 0) {
            vaccinatedQuantity++;
        }
    }

    return vaccinatedQuantity;
}

// Get confined members
int confinedMembers(communityMember arrayMember[MAX_MEMBERS], int membersQuantity) {
    int i = 0;
    int confinedQuantity = 0;

    for (; i < membersQuantity; i++) {
        // Checks if member not confined (0) or in quaratine/isolation (1/2)
        if (arrayMember[i].confinmentState > 0) {
            confinedQuantity++;
        }
    }

    return confinedQuantity;
}
