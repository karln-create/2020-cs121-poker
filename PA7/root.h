#ifndef ROOT_H
#define ROOT_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "prep.h"
#include "core.h"
#include "combocheck.h"

#define HAND_CARDS 5   /* maximum number of cards in a Hand */

/* declare the struct card to store information about a specific card */
typedef struct card {
    int suit;
    int face;
} Card;

/* declare the struct hand to store information about the player's drawn cards and quality of Hand */
typedef struct hand {
    struct card pHand[5];
    int hQuality;
    
} Hand;

/* declare an enum type to flag the quality of the Hand */
enum hQual {
    NOTHING, TWOPAIRS, TWOSAME, THREESAME, FOURSAME, FLUSH, STRAIGHT
};

#endif