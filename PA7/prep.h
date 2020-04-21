/*
	contains functions related to prepping the game such as shuffling the card deck and dealing cards to each player.
*/

void shuffle(int wDeck[][13]);

void deal(int wDeck[][13], const char *wFace[], const char *wSuit[], struct hand *p_player);

void print_pHand(struct hand player);