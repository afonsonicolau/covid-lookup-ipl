// Headers
#include "members.h"
#include "aux_functions.h"

void listConfinmentCases(communityMember arrayMember[MAX_MEMBERS], int membersQuantity) {
    if (membersQuantity <= 0) {
        printf("\n\tIts impossible to list confinment cases when members dont exist!");
        pressToRedirect();
        return;
    }

    int i = 0;
    printf("\n\tListing Confinment Cases...\n");

    for (; i < membersQuantity; i++) {
        if (arrayMember[i].confinmentState > 0) {
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
}

void updateConfinmentState(communityMember arrayMember[MAX_MEMBERS], int membersQuantity) {
    if (membersQuantity <= 0) {
        printf("\n\tIts impossible to update members when they dont exist!");
    }
    else {
        int position = searchMember(arrayMember, membersQuantity, 0);

        if (position != -1) {
            printf("\n\tEditing %s:\n", arrayMember[position].name);
            arrayMember[position].confinmentState = readInt("New Confinment State (0 - Not Confined || 1 - Quarantine || 2 - P. Isolation)", 0, 2);

            printf("\n\tMember confinment state was updated...\n\n");
        }
        else {
            printf("\n\tThis member doesnt exist...\n\n");
        }
    }

    pressToRedirect();
}
