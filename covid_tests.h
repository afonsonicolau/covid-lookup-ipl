#ifndef COVID_TESTS_H_INCLUDED
#define COVID_TESTS_H_INCLUDED

#include "aux_functions.h"

// Structures
typedef struct {
    int id;
    int snsNumber;
    int type;
    int result;
    int duration;
    time timeTaken;
    date dateTaken;
} diagnosticTest;

#endif