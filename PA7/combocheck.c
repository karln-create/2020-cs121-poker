#include "root.h"

int find_dup(struct card player[], int num_dup)
{
	int i, pass, counter = 1;
	
	for (pass = 0; pass <= HAND_CARDS - num_dup; ++pass)
	{
		int temp = player[pass].face;
		if (counter == num_dup) break;
		else {
			counter = 1; /* reset the counter if not enough duplicates were found */
			for (i = pass; i < HAND_CARDS - 1; ++i)
			{
				if (temp == player[i + 1].face)
					++counter;
			}
		}
	}

	if (counter == num_dup) return 1;
	else return 0;
}

int find_twopairs(struct card player[])
{
	int temparr[5] = { 0 };
	int i, pass, counter = 0;
	int temp;

	for (pass = 0; pass <= HAND_CARDS - 2; ++pass)
	{
		if (counter == 2) break;
		
		temp = player[pass].face;
		for (i = pass; i < HAND_CARDS - 1; ++i)
		{
			if (counter == 2) break;
			else if (temp == player[i + 1].face)
			{
				++counter;
				temparr[pass] = 1;
				temparr[i + 1] = 1;
			}
		}
	}

	counter = 1;
	for (int j = 0; j < HAND_CARDS; ++j)
	{
		if (counter == 2) break;

		else if (temparr[j] == 1) continue;
		
		else {
			for (pass = j; pass < HAND_CARDS - j; ++pass)
			{
				if (counter == 2) break;

				temp = player[j].face;
				for (i = pass; i < HAND_CARDS - 1; ++i)
				{
					if (counter == 2) break;
					else if (temp == player[i + 1].face)
					{
						++counter;
						temparr[pass] = 2;
						temparr[i + 1] = 2;
					}
				}
			}
		}
	}

	counter = 0;
	for (i = 0; i < HAND_CARDS; ++i)
	{
		if (counter == 4) break;
		else if (temparr[i] == 1) ++counter;
		else if (temparr[i] == 2) ++counter;
	}
	
	if (counter == 4) return 1;
	else return 0;
}

int find_straight(struct card player[])
{
	int temp[HAND_CARDS] = { 0 }, aux[HAND_CARDS] = { 0 };
	/* copy face values into a local temp array */
	for (int i = 0; i < HAND_CARDS; ++i) { temp[i] = player[i].face; }
	/* merge sort before varifying values */


	return 0;
}

void save_hQuality(struct hand player, int found, int input)
{
	if (found == 1)
		{
			printf("FOUND!\n");
			switch (input)
			{
			case TWOPAIRS:
				printf("TWO PAIRS!\n");
				player.hQuality = TWOPAIRS;
				break;
			case TWOSAME:
				printf("ONE PAIR!\n");
				player.hQuality = TWOSAME;
				break;
			case THREESAME:
				printf("THREE OF A KIND!\n");
				player.hQuality = THREESAME;
				break;
			case FOURSAME:
				printf("FOUR OF A KIND!\n");
				player.hQuality = FOURSAME;
				break;
			case FLUSH:
				printf("FLUSH!\n");
				player.hQuality = FLUSH;
				break;
			case STRAIGHT:
				printf("STRAIGHT!\n");
				player.hQuality = STRAIGHT;
				break;
			}
		}
		else
		{
			printf("NOT FOUND. MIGHT BE SOMETHING ELSE.\n");
			player.hQuality = NOTHING;
		}
}

void merge_s(int arr[], int aux[], int left, int right)
{
	if (left < right)
	{	
		// get mid from i and j to feed in recursive calls.
		int mid = left + (right - left) / 2;		// to prevent stack overflow.
		// immediately call recursive to get to the base cases.
		merge_s(arr, aux, left, mid);
		merge_s(arr, aux, mid + 1, right);

		int i = left;
		int	j = mid + 1;	
		int k;

		for (k = left; k <= right; ++k)
		{
			if (i == mid + 1)
			{
				aux[k] = arr[j];
				++j;
			}
			else if (j == right + 1)
			{
				aux[k] = arr[i];
				++i;
			}
			else if (arr[i] < arr[j])
			{
				aux[k] = arr[i];
				++i;
			}
			else
			{
				aux[k] = arr[j];
				++j;
			}
		}

		for (k = left; k <= right; ++k)
			{
				arr[k] = aux[k];
			}
	}
}