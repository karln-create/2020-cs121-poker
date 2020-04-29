# PA7 -- 5-Card-Draw Poker

Description: 5-Card-Draw Poker played between a Player and Bot.


# Development Guideline:

    KEEP THE PROGRAM LEAN AND SIMPLE! NO MORE BL

    Must start with the base code supplied by Deitel & Deitel. This basecode can be found in a text file in the project directory.

## 1. Core functions:

        a) Declare a struct Card that contains two integers: -----> index of the face of the card (in the array of strings of faces)
                                                            \
                                                             `----> index of the suit of the card (in the array of strings of suits)

        b) Declare a struct Hand that contains an array of 5 struct Cards.

        c) Create a menu that allows the user to view the game rules, play the game, and exit the game.

        d) Modify the card dealing function provided in the base code so that a poker Hand is dealt. You should be able to use this this function to deal and draw any number of cards.

        e) Write functions to determine if the Hand contains: -----> one pair.  (flag: combocheck = 1)
                                                             \
                                                              `----> two pair.  (flag: combocheck = 2)
                                                             \
                                                              `----> 3-o-a-kind (e.g. three Jacks).     (flag: combocheck = 3)
                                                             \
                                                              `----> 4-o-a-kind (e.g. four Aces).       (flag: combocheck = 4)
                                                             \
                                                              `----> a flush (e.g. five cards of the same suit).    (flag: combocheck = 5)
                                                             \
                                                              `----> a straight (e.g. five cards of consecutive face values).   (flag: combocheck = 6)

## 2. Simulating the Dealer:

        The Dealer's five-card Hand is dealt "face-down" so the Player cannot see it.
        a) The program should then evaluate the Dealer's Hand.
        b) Based on the quality of the Hand, the Dealer should draw one, two, or three more cards to replace the corresponding number of unneeded cards in the original Hand.
        c) The program should then re-evaluate the Dealer's Hand.

## 3. Automating the Dealer's five-card Hand:

        a) Make the program handle the Dealer's five-card Hand automatically.
        b) The Player should be allowed to decided which cards of their Hand to replace.
        c) The program should then evaluate both Hands and determine who wins.
        d) The game should be played until the user wants to exit.

    4. Other notes: May make any adjustments or customizations to my Poker game as wanted. Have fun!


# Game Rules:

    A play begins by having five cards dealt to each player, one at a time, all face down.
    
    The remaining deck is placed aside. The players then pick up the cards and hold them in their Hands, concealing them from other players.
    
    Then a round of betting starts.

## 1. First betting round:

    Home game: the first betting round begins with the player to the Dealer's left, and the second round begins with the player who opened the first round.

    (*) Since this program only has 2 players (human-player and Bot), it will follow the 'ante' rule, i.e. each player must put their ante into the pot before the deal begins.
    
    A coin flip will then determine who will open the game. Then the other player may decide to call or fold.

    If more than one player remains after the first round, the "draw" phase begins.

## 2. Draw phase:

    Each player specifies how many of their cards they wish to replace, and then discards those cards.
    
    Each player is then dealt in turn from the deck the same number of cards they discarded, so that each player again has five cards.
    
## 3. Second betting round (after the 'draw'):

    This betting round starts with the player to the Dealer's left, or else beginning with the player who opened the first round.

    This is followed by a showdown, if more than one player remains, in which the player with the best Hand wins the pot.


# Program Description:

    The program starts first with a main menu with three options: read game rules, play game, exit. If the player chooses to read the rules, the program will display the 
    complete rules and then loop back to the main menu. If the player chooses 'exit', the program will terminate. If the player chooses to play a game, the program will
    lead to the next functionality.

    The 'play' functionality:
    This functionality is broken down into smaller sub functionalities (or subs).
    1. The first sub, the 'Ante betting', deals with the inital bets from both players (Human and Bot).
    2. The second sub, "prepping", deals with the shuffling and dealing of a Hand (total of 5 cards). Basically preparing the table for the players.
    3. The third sub, 'Draw', is divided into two parts: one for the Human and one for the Bot.
        3_P)    The Draw_Human allows the human player to pick and discard selected cards, and then draw new cards from the array of shuffled cards.
        3_Bot)  The Draw_Bot is a little more complicated considering that it incorporates the combo checking algorithm to check for the quality of its Hand.
                    
                    The Draw_Bot is broken down further into "quality_check" and "Draw_actual".
                    The quality_check is supplied by a library of algorithms that can help determine possible combos. Once Hand's quality is checked, a numerical value between
                    1 and 5 will be sent down to Draw_actual to get new cards.
                    For example, if the Hand is of the lowest quality, i.e. no combos whatsover, then the value '5' will be supplied to the Draw_actual to get 5 fresh cards.
                    Another example, if the Hand contains a pair, then quality_check will keep the '2' cards and send '3' to the Draw_actual algorithm to draw 3 fresh cards and so on.

    4. Once all players have finished drawing, the fourth sub compares both Hands for the better Hand to determine the winner.

    Once the winner is found, the program will ask the player whether they want to continue or return to exit. If 'exit' then the program terminates.


# Development History:
Update | 2020/04/27/MON, 14:35 PDT
    Write a a linear search function to check for duplicates.

Update | 2020/04/22/WED, 12:48 PDT
    I must write the combo checking algorithms for the Bot player. There is no way around it.

Update | 2020/04/22/WED, 11:55 PDT
    TO-DO: Build algorithm checking for onepair using binary search.
            Set a quality flag for the Hand's quality with enum.

Update | 2020/04/21/TUE, 19:22 PDT
    DONE: the draw phase (for the Human player) is done. Will go back to modify for the Bot player at a different time.
    TO-DO: Combo checking algorithms. Review algorithms from Yahtzee (PA5).

Update | 2020/04/21/TUE, 14:20 PDT
    DONE: modifying the deal function for both the Human and Bot players. Also modified it to update the card deck with the dealt cards removed from the deck's pool.
    TO-DO: Skip the Betting phses for now, focus on getting a complete deal-draw-compare sequence running.
           Start work on the Draw phase for the Human player.

Update | 2020/04/21/TUE, 13:22 PDT
    WORKING ON: modifying the deal function to deal out 5 cards to the Human player.

Update | 2020/04/20/Mon, 11:52 PDT
    TO-DO: Make a sample deal for the Human Player by combine the shuffle and deal functions.

Update | 2020/04/19/Sun, 21:39 PDT
    TO-DO: Must understand how the data structures for deck and Hands are set up before proceeding further.

Update | 2020/04/19/Sun, 17:37 PDT
    TO-DO: Start work on the Ante Betting part.

Update | 2020/04/19/Sun, 15:10 PDT
    TO-DO: Implement the welcome screen and main menu.

Update | 2020/04/18/Sat, 23:18 PDT
    Working on a flowchart using Lucidchart. Should have a design ready by tomorrow.

Update | 2020/04/18/Sat, 22:09 PDT
    Broken down the game rules into workable chunks.
    TO-DO: Sketch a design for the program.

Update | 2020/04/18/Sat, 10:40 PDT
    TO-DO: Write down the game rules and implement the menu option for reading game rules.

Update | 2020/04/18/Sat, 10:28 PDT
    I messed around with merging local repos and accidentally deleted my project that I started a week ago. I lost the README file and the source code.
    Thankfully there wasn't a lot of progress yet so the loss wasn't too bad.