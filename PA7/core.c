#include "root.h"

/* execute the game between the Human player and the Computer */
void game()
{
	/* initialize memory arrays of suit and face, to be referenced through out the game */
	const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	const char *face[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
							"Nine", "Ten", "Jack", "Queen", "King"};

	printf("GAME START ----->\n");

	/* initialize variable array for the standard deck of 52 cards */
	int deck[4][13] = { 0 };

	Hand pHuman = { 0 }, pBot = { 0 };

	shuffle(deck);
	deal(deck, &pHuman);
	deal(deck, &pBot);

	print_pHand(pHuman, suit, face);
	/* redraw cards (if any discarded) */
	draw_phase(deck, pHuman);
	draw_phase(deck, pBot);

	int coinflip = rand() % 2;

	/* add a while loop here later to play until player wants to quit */
	if (coinflip == 0)
	{
		play_Human(pHuman, suit, face);
		play_Bot(pBot, suit, face);
	}
	else if (coinflip == 1)
	{
		play_Bot(pBot, suit, face);
		play_Human(pHuman, suit, face);
	}
	
}


/* allows the player to redraw a number of cards (at a maximum of 5 cards) */
void draw_phase(int wDeck[][13], struct hand player)
{
	int cards_discarded[5] = { 0 };
	int cards_drawn[5] = { 0 };
	int i;
	char input = '\0';

	printf("\nwhich cards do you want to discard? Enter y or n.\n");

	/* iterate through 5 cards in Hand */
	for (i = 0; i < 5; ++i)
	{
		printf("discard card #%d? ", i + 1);
		while (input == '\0')
		{
			scanf(" %c", &input);
			if (!(input == 'y' || input == 'Y' || input == 'n' || input == 'N'))
				input = '\0';

		}

		if (input == 'n' || input == 'N') continue;

		else if (input == 'y' || input == 'Y')
			draw_one_card(wDeck, player, input);

		input = '\0';
	}

}

void play_Human(struct hand player, const char* wSuit[], const char* wFace[])
{
	int found = -1, input = -1;
	/* check for simple duplicates: one air, three-o-kind, four-o-kind, flush */
	while (found == -1)
	{
		print_pHand(player, wSuit, wFace);
		while (input == -1)
		{
			printf("Enter a number for the combo: ");
			scanf(" %d", &input);
			if (input > 6 || input < 1)
				input = -1;
		}

		if (input <= 5 && input >= 2)
		{
			found = find_dup(player.pHand, input);
			break;
		}
		else if (input == 1)
		{
			found = find_twopairs(player.pHand);
			break;
		}
		else if (input == 6)
		{
			found = find_straight(player.pHand);
			break;
		}
	}

	save_hQuality(player, found, input);

}

void play_Bot(struct hand payer, const char* wSuit[], const char* wFace[])
{

}