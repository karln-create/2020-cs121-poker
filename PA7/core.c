#include "root.h"

/* execute the game between the Human player and the Computer */
void play_game(const char* face[], const char* suit[])
{
		printf("GAME START -->\n\n");

	/* initialize variable array for the standard deck of 52 cards */
	int deck[4][13] = {0};



	Hand pHuman = { 0 },
		 pBot  = { 0 };

	shuffle(deck);
	deal(deck, face, suit, &pHuman);
	deal(deck, face, suit, &pBot);

}


/* allows the player to redraw a number of cards (at a maximum of 5 cards) */
void draw_phase()
{
	int cards_drawn = 0;

}