/*
	KARL NORDEN, CLASS: CPTS121 SECTION 17
	DESCRIPTION: 5-Card-Draw Poker game.
*/
#include "root.h"

void print_welcome(void);
int get_INT_input(int input);
void print_gamerules(void);

int main(void)
{
	/* initialize memory arrays of suit and face, to be referenced through out the game */
	const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	const char *face[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
							"Nine", "Ten", "Jack", "Queen", "King"};

	
	srand((unsigned)time(NULL)); /* seed random-number generator. */

	
	/* initialize a variable for menu input */
	int mainmenu_input = 0;

	 while (mainmenu_input == 0)
	{
		print_welcome();
		mainmenu_input = get_INT_input(mainmenu_input);
	
		if(mainmenu_input == 1)			/* control switch for printing the game rules */
		{
			print_gamerules();
			system("pause");
			mainmenu_input = 0;
		}
		else if (mainmenu_input == 2)	/* control switch for starting a new poker game */
		{
			play_game(suit, face);
			system("pause");
			mainmenu_input = 0;
		}
		else if (mainmenu_input == 3)	/* control switch for exiting the program */
		{
			system("pause");
			break;
		}
		else
		{
			printf("\tInvalid input.\n");
			mainmenu_input = 0;
		}
	}


	return 0;
}

/* print the welcome menu */
void print_welcome(void)
{
	printf("\n\n*********** WELCOME TO 5-CARD-DRAW POKER! ******************************\n\n");
	printf("\tMAIN MENU:\t1. READ GAME RULES\n\t\t\t2. PLAY A GAME\n\t\t\t3. EXIT GAME\n");
	printf("\n\tEnter your selection: ");
}

/* ask for an integer input for the menu options */
int get_INT_input(int input)
{
	scanf(" %d", &input);
	return input;
}

/* display the game rules */
void print_gamerules(void)
{
	printf("\n(*) GAME RULES FROM WIKIPEDIA ENTRY ON 5-CARD-DRAW POKER (*) ----------------------------------------------");
	printf("\n\nThe game starts with the Ante Betting Round.");
	printf("\nBoth players must throw in an equal amount of starting bets (here $5).");
	printf("\nA play begins by having five cards dealt to each player, one at a time, all face down.");
	printf("\nThe remaining deck is placed aside. The players then pick up the cards and hold them in Hands,\nconcealing them from other players.");
	printf("\nThen the Dealer flips a coin to determine which player will be the Opener.");
	printf("\n\nThen the First Betting Round begins.");
	printf("\nThe Opener will then have the choice to Raise or Fold.");
	printf("\nIf the Opener Raise, then the Follower may choose to Call or Fold.");
	printf("\nIf the Opener decides to Draw then the players enter the Draw Phase.");
	printf("\nEach player then specifies how many of their cards they wish to replace, and then discards those cards.");
	printf("\nEach player is then dealt in turn from the deck the same number of cards they previously discarded, \nso that each player again has five cards.");
	printf("\n\nThen the Second Betting Round begins.");
	printf("\nThis round starts with the player who opened the First Betting Round.");
	printf("\nFollowing this betting round is a show-down, in which the player with the best Hand wins.");
	printf("\n\n");

}