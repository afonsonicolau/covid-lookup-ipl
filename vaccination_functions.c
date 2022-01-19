#include <stdio.h>

// Headers
#include "members.h"
#include "aux_functions.h"

void registerVaccination(communityMember arrayMember[MAX_MEMBERS], int quantity) {
    if (quantity <= 0) {
        printf("\n\tIts impossible to update members when they dont exist!");
        pressToRedirect();
        return;
    }

    int memberExists = searchMember(arrayMember, quantity, 0);

    // Cheks if member exists, if it doesn't it returns to main menu after a key is pressed
    if(memberExists == -1) {
        printf("\n\tThere are no members with given SNS Number");
        pressToRedirect();
        return;
    }

    // Check if member has already taken a vaccine
    if (arrayMember[memberExists].vaccinationState != 0) {
        printf("\n\tThis member has already taken a vaccine...");
        pressToRedirect();
        return;
    }

    // After all validations, member is registered as vaccinated
    arrayMember[memberExists].vaccinationState = 1;
    arrayMember[memberExists].lastVaccine = readDate("Date Vaccine was Applied");
    printf("\n\tMember was registered with FIRST dose, 1 more!");
    pressToRedirect();
}

void updateVaccination(communityMember arrayMember[MAX_MEMBERS], int quantity) {
    if (quantity <= 0) {
        printf("\n\tIts impossible to update members when they dont exist!");
        pressToRedirect();
        return;
    }

    int memberExists = searchMember(arrayMember, quantity, 0);

    // Cheks if member exists, if it doesn't it returns to main menu after a key is pressed
    if(memberExists == -1) {
        printf("\n\tThere are no members with given SNS Number");
        pressToRedirect();
        return;
    }

    // Check if member has already taken a vaccine
    if (arrayMember[memberExists].vaccinationState == 0) {
        printf("\n\tThis member doesn't have any vaccine yet...");
        pressToRedirect();
        return;
    }

    // After all validations, member is registered as vaccinated
    arrayMember[memberExists].vaccinationState++;
    arrayMember[memberExists].lastVaccine = readDate("Date Vaccine was Applied");
    printf("\n\tMember was registered with %d dose!", arrayMember[memberExists].vaccinationState);
    pressToRedirect();
}
