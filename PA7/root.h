#ifndef ROOT_H
#define ROOT_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prep.h"
#include "core.h"

/* declare the struct card to store information about a specific card */
typedef struct card {
    int suit;
    int face;
} Card;

/* declare the struct hand to store information about the player's drawn cards */
typedef struct hand {
    struct card pHand[5];
} Hand;

#endif 