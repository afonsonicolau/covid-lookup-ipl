#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Constants
#define MAX_MEMBERS 200
#define MAX_STRING 50

// Structures
typedef struct
{
    int day;
    int month;
    int year;
} date;

typedef struct
{
    int hour;
    int minute;
} time;

typedef struct
{
    int snsNumber;
    char name[50];
    date birthDate;
    int memberRole;
    int confinmentState;
    int vaccinationState;
    date lastVaccine;
} communityMember;

typedef struct
{
    int id;
    int snsNumber;
    int type;
    int result;
    int duration;
    time timeTaken;
    date dateTaken;
} diagnosticTest;

// Functions
int mainMenu()
{
    int optionChoosen;

    do
    {
        printf("\t**************************************************");
        printf("\n\t** \t\t\t\t\t\t**");
        printf("\n \t** \t\tCOVID Lookup System \t\t**");
        printf("\n\t** \t\t\t\t\t\t**");
        printf("\n\t**************************************************");

        printf("\n\n\tMembers Inserted: %d \t\tTests Scheduled: %d", 1, 1);
        printf("\n\tMembers Vaccinated: %d \t\tTests Performed: %d", 1, 1);

        printf("\n\n\t1. Member Options");
        printf("\n\t2. Vaccination Options");
        printf("\n\t3. Test Options");
        printf("\n\t4. Confinment Options");

        printf("\n\n\tOption: ");
        scanf("%d", &optionChoosen);

    } while (optionChoosen != '1' && optionChoosen != '2' && optionChoosen != '3' && optionChoosen != '4');

    return optionChoosen;
}

void program_menu() // Function that triggers the program menu
{
    char option;

    switch (option)
    {
    case '1': // Member Options

        break;
    case '2': // Vaccination Options

        break;
    case '3': // Test Options
        break;

    case '4': // Confinment Options
        break;

    default:
        break;
    }
}

void cleanBuffer(void)
{
    char char_check;

    do
    {
        char_check = getchar();
    } while (char_check != '\n' && char_check != EOF);
}

float readFloat(char message[MAX_STRING], float min, float max)
{
    float number;
    int control;
    do
    {
        printf("%s (%.2f a %.2f) :", message, min, max);
        control = scanf("%f", &number);
        limpaBufferStdin();

        if (control == 0)
        {
            printf("You must insert a float number: \n");
        }
        else
        {

            if (number<min || number>max)
            {
                printf("Invalid number, try again: \n");
            }
        }
    } while (number<min || number>max || control == 0);

    return number;
}

int readInt(char message[MAX_STRING], int min, int max)
{
    int number, control;

    do
    {
        printf("%s (%d a %d) :", message, min, max);
        control = scanf("%d", &number);
        cleanBuffer();

        if (control == 0)
        {
            printf("You must insert an integer \n");
        }
        else
        {
            if (number < min || number > max)
            {
                printf("Invalid number, insert again...: \n");
            }
        }
    } while (number < min || number > max || control == 0);

    return number;
}

void readString(char message[MAX_STRING], char arrayChar[MAX_STRING], int maxChar)
{
    int sizeString;

    do
    {
        printf("%s", message);
        fgets(arrayChar, maxChar, stdin);

        sizeString = strlen(arrayChar);

        if (sizeString == 1)
        {
            printf("Please insert some information!\n\n");
        }
    } while (sizeString == 1);

    if (arrayChar[sizeString - 1] != '\n')
    {
        cleanBuffer();
    }
    else
    {
        arrayChar[sizeString - 1] = '\0';
    }
}

date readDate(void)
{
    date date_read;
    int maxDaysMonth;

    date_read.month = readInt(" year", 2014, 2020);
    date_read.month = readInt(" month", 1, 12);

    switch (date_read.month)
    {
    case 2:
        if ((date_read.year % 400 == 0) || (date_read.year % 4 == 0 && date_read.year % 100 != 0))
        {
            maxDaysMonth = 29;
        }
        else
        {
            maxDaysMonth = 28;
        }
    case 4:
    case 6:
    case 9:
    case 11:
        maxDaysMonth = 30;
        break;
    default:
        maxDaysMonth = 31;
    }

    date_read.day = readInt(" day:", 1, maxDaysMonth);
}

int createMember(communityMember arrayMember[MAX_MEMBERS], int quantity)
{
    int vaccination;
    int confinment;
    date date_member;
    int position;
    communityMember infoMember;

    if (quantity == MAX_MEMBERS)
    {
        printf("You can´t create more community members!");
    }
    else
    {
        infoMember = readFromMember();

        position = searchMember(arrayMember, quantity, infoMember.snsNumber);

        if (position == -1)
        {
            arrayMember[quantity] = infoMember;
            vaccination = readFloat("Vaccination State: ");
            arrayMember[quantity].vaccinationState = vaccination;
            date_member = readDate();
            arrayMember[quantity].confinmentState = confinment;
            quantity++;
        }
        else
        {
            printf("This member is already registered... \n");
        }
    }
}

// Main function
int main()
{
    communityMember member[MAX_MEMBERS];

    mainMenu();

    return 0;
}
