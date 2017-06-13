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
	    ("Ультра енот\n\nВы - енот, который должен красть, мыть и отпускать рыбу.\nЕсть ещё одна опасность - пьяный охотник в кусте.\n");
	for (;;) {
		fisherman_flag = (int)(2.0 * rand() / (RAND_MAX + 1.0));
		gun_pos = (int)(3.0 * rand() / (RAND_MAX + 1.0));
		if (fishes == 0)
			printf("Ваши лапы пусты.\n");
		if (fishes > 0 && wash_flag == 0)
			printf("Ваша рыба грязная.\n");
		printf("Выбирайте: 1) красть; 2) мыть; 3) отпускать;\n\?");
		do {
			scanf("%d", &tty_in);
		} while (tty_in < 1 || tty_in > 3);
		if ((tty_in - 1) == gun_pos) {
			printf
			    ("Вы убиты пьяным охотником в кусте. %d рыб благодарны Вам.\n\nИГРА ОКОНЧЕНА\n",
			     rfc);
			return 0;
		}
		switch (tty_in) {
		case 1:
			if (fisherman_flag) {
				printf
				    ("Вы пойманы рыбаком. %d рыб благодарны Вам.\n\nИГРА ОКОНЧЕНА\n",
				     rfc);
				return 0;
			}
			fishes += 1;
			wash_flag = 0;
			break;
		case 2:
			if (fishes > 0) {
				printf("Мытьё рыб так утомляет...\n");
				wash_flag = 1;
			} else
				printf("У Вас нечего мыть!\n");
			break;
		case 3:
			if (fishes > 0 && wash_flag == 0)
				printf
				    ("Вы не можете отпустить грязную рыбу!\n");
			if (fishes == 0)
				printf
				    ("Вы не можете отпустить воздух в своих лапах!\n");
			if (fishes > 0 && wash_flag == 1) {
				printf("Пока-пока, милые рыбки!\n");
				rfc += fishes;
				fishes = 0;
				wash_flag = 0;
			}
			break;
		}
	}
	return 0;
}
