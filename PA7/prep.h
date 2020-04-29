#pragma once
/*
	contains functions related to prepping the game such as shuffling the card deck and dealing cards to each player.
*/

void shuffle(int wDeck[][13]);

void deal(int wDeck[][13], struct hand* player);

void print_pHand(struct hand player, const char* wSuit[], const char* wFace[]);

void draw_one_card(int wDeck[][13], struct hand player, int input);