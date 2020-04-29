#pragma once
/*
	contains all functions related to checking for quality of Hand:
		- one pair, two pair, 3-o-akind, 4-o-akind, flush, straight
*/

/* if validated, return 1, otherwise return 0 */
int find_dup(struct card player[], int num_dup);

/* if validated, return 1, otherwise return 0 */
int find_twopairs(struct card player[]);

/* if validated, return 1, otherwise return 0 */
int find_straight(struct card player[]);

/* once validated, save the Hand's quality into specific player's struct */
void save_hQuality(struct hand player, int found, int input);

/* merge sort */
void merge_s(int arr[], int aux[], int left, int right);