#include "root.h"

/* shuffle cards in the deck (a 2-dim array of size 4 by 13) */
void shuffle(int wDeck[][13])
{
	int row = 0;  // row number
	int col = 0;  // col number
	int card = 0; // card counter

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			col = rand() % 13;
		} while (wDeck[row][col] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][col] = card;
	}
}


/* deal cards from deck */
void deal(int wDeck[][13], struct hand *player)
{
	int row = 0;  // row number
	int col = 0;  // col number
	int card = 0; // counter for cards in Hand

	/* deal each of the 52 cards from deck */
	for (card; card < 5; card++)
	{
		do
		{
			row = rand() % 4;
			col = rand() % 13;

		} while (wDeck[row][col] == 0);

		player->pHand[card].suit = row;
		player->pHand[card].face = col;
		wDeck[row][col] = 0;
	}
}

void print_pHand(struct hand player, const char* wFace[], const char* wSuit[])
{
	int f = 0, s = 0;
	int i;


	for (i = 0; i < 5; ++i)
	{
		s = player.pHand[i].suit;
		f = player.pHand[i].face;

		printf("[%5s : %-8s%c]\t", wSuit[s], wFace[f]);
	}
}

/* draw one new card */
void draw_one_card(int wDeck[][13], struct hand player, int input)
{
	int row = 0;  // row number
	int col = 0;  // col number

	do
		{
			row = rand() % 4;
			col = rand() % 13;

		} while (wDeck[row][col] == 0);

		player.pHand[input].suit = row;
		player.pHand[input].face = col;
		wDeck[row][col] = 0;
}