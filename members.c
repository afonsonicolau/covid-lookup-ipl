#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Files
#include "aux_functions.h"
#include "members.h"


communityMember readFromMember(void)
{
    communityMember data;

    data.snsNumber = readInt("SNS number: ", SNSNUMBER_MIN, SNSNUMBER_MAX);

    readString("Name of the member: ", data.name, MAX_STRING);

    data.vaccinationState = readInt("Vaccination State: ", MAX_FALSE, MAX_TRUE);

    data.confinmentState = readInt("Confinment State: ", MAX_FALSE, MAX_TRUE);

    data.memberRole = 0;

    return data;
}

int searchMember(communityMember arrayMember[MAX_MEMBERS], int quantity, int snsNumber) {
    int i;
    int position = -1;

    for (i = 0; i < quantity; i++) {

        if (arrayMember[i].snsNumber == snsNumber) {
            position = i;
            i = quantity;
        }
    }
    return position;
}

void createMember(communityMember arrayMember[MAX_MEMBERS], int quantity) {
    char vaccination;
    date date_member;
    int position;
    communityMember infoMember;

    if (quantity == MAX_MEMBERS) {
        printf("You can´t create more community members!");
    }
    else {
        infoMember = readFromMember();

        position = searchMember(arrayMember, quantity, infoMember.snsNumber);

        if (position == -1) {
            arrayMember[quantity] = infoMember;
            date_member = readDate();
            quantity++;
        }
        else {
            printf("This member is already registered... \n");
        }
    }
}

