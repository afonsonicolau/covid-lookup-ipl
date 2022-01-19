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

communityMember readNewMemberInfo() {
    communityMember data;

    data.snsNumber = readInt("SNS number", SNSNUMBER_MIN, SNSNUMBER_MAX);
    readString("Name of the member", data.name, MAX_STRING);
    data.birthDate = readDate();
    data.vaccinationState = readInt("Vaccination State", MAX_FALSE, MAX_TRUE);
    data.confinmentState = readInt("Confinment State", MAX_FALSE, MAX_TRUE);
    data.memberRole = 0;

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
        printf("You can´t create more community members!");
    }
    else {
        infoMember = readNewMemberInfo();

        position = searchMember(arrayMember, *quantity, infoMember.snsNumber);

        if (position == -1) {
            arrayMember[*quantity] = infoMember;
            *quantity++;

            printf("\n\tA new member was created, redirecting to main menu...");
        }
        else {
            printf("\n\tThis member is already registered, redirecting to main menu...");
        }

        mainMenu(arrayMember, *quantity);
    }
}

void listMembers(communityMember arrayMember[MAX_MEMBERS], int quantity) {
    int i = 0;
    printf("\n\n\n%d", quantity);
    printf("\n\tListing Members...");
    for (; i < quantity; i++) {
        printf("\n\n\tSNS Number: %d", arrayMember[i].snsNumber);
        printf("\n\tName: %s", arrayMember[i].name);
        printf("\n\tDate of Birth: %d/%d/%d", arrayMember[i].birthDate.day, arrayMember[i].birthDate.month, arrayMember[i].birthDate.year);

        // Reads memberRole value and associates it's description to it
        if (arrayMember[i].memberRole == 0) printf("\n\tRole: Student");
        else if (arrayMember[i].memberRole == 1) printf("\n\tRole: Teacher");
        else if (arrayMember[i].memberRole == 1) printf("\n\tRole: Technician");
        else printf("\n\tSomething went wrong, can't read member role.");

        // Get member vaccionation state and verify it's value in order to show correct result to user
        if (arrayMember[i].vaccinationState == 0) printf("\nIs member vaccinated: No");
        else if (arrayMember[i].vaccinationState == 1) printf("\nIs member vaccinated: Yes");
        else printf("\nSomething went wrong, can't read member vaccination state.");

        // Get member confinment state and verify it's value in order to show correct result to user
        if (arrayMember[i].confinmentState == 0) printf("\nIs member confined: No");
        else if (arrayMember[i].confinmentState == 1) printf("\nIs member confined: Yes");
        else printf("\nSomething went wrong, can't read member confinment state.");
    }
}
