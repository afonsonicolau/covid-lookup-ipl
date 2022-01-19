#ifndef AUX_FUNCTIONS_H_INCLUDED
#define AUX_FUNCTIONS_H_INCLUDED

// Constants
#define MAX_STRING 75

// Structures
typedef struct {
    int day;
    int month;
    int year;
} date;

typedef struct {
    int hour;
    int minute;
} time;

// Functions
void cleanBuffer(void);
float readFloat(char message[MAX_STRING], float min, float max);
int readInt(char message[MAX_STRING], int min, int max);
void readString(char message[MAX_STRING], char arrayChar[MAX_STRING], int maxChar);
date readDate(char message[MAX_STRING]);
time readTime(char message[MAX_STRING]);
void pressToRedirect();

#endif
