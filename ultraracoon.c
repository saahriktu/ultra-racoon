/*
 * "Ultra racoon" game
 * 2014 (c) Kurashov A.K.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(0));
	int fishes = 0, wash_flag = 0, fisherman_flag, gun_pos, tty_in, rfc = 0;
	printf
	    ("Ultra racoon\n\nYou are racoon and you must steal, wash and release fish.\nThere is one more danger - sozzled hunter in a bush.\n");
	for (;;) {
		fisherman_flag = (int)(2.0 * rand() / (RAND_MAX + 1.0));
		gun_pos = (int)(3.0 * rand() / (RAND_MAX + 1.0));
		if (fishes == 0)
			printf("Your paws are empty.\n");
		if (fishes > 0 && wash_flag == 0)
			printf("Your fishes are dirty.\n");
		printf("Choose: 1) steal; 2) wash; 3) release;\n\?");
		do {
			scanf("%d", &tty_in);
		} while (tty_in < 1 || tty_in > 3);
		if ((tty_in - 1) == gun_pos) {
			printf
			    ("You was killed by sozzled hunter in a bush. %d fishes thankful to You.\n\nGAME OVER\n",
			     rfc);
			return 0;
		}
		switch (tty_in) {
		case 1:
			if (fisherman_flag) {
				printf
				    ("You was caught by fisherman. %d fishes thankful to You.\n\nGAME OVER\n",
				     rfc);
				return 0;
			}
			fishes += 1;
			wash_flag = 0;
			break;
		case 2:
			if (fishes > 0) {
				printf("Washing of fishes is so tiring...\n");
				wash_flag = 1;
			} else
				printf("You have nothing to wash!\n");
			break;
		case 3:
			if (fishes > 0 && wash_flag == 0)
				printf("You cann't release dirty fish!\n");
			if (fishes == 0)
				printf
				    ("You cann't release air in your paws!\n");
			if (fishes > 0 && wash_flag == 1) {
				printf("Bye, bye dear fishes!\n");
				rfc += fishes;
				fishes = 0;
				wash_flag = 0;
			}
			break;
		}
	}
	return 0;
}
