#pragma once
/*
	contains all functions strictly related to constructing an instance of gaming.
*/

void game(/*const char *wSuit[], const char *wFace[]*/);

void draw_phase(int wDeck[][13], struct hand player);

void play_Human(struct hand player, const char* wSuit[], const char* wFace[]);

void play_Bot(struct hand player, const char* wSuit[], const char* wFace[]);
