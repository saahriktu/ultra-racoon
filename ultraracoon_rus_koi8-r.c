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
	    ("������ ����\n\n�� - ����, ������� ������ ������, ���� � ��������� ����.\n���� �ݣ ���� ��������� - ������ ������� � �����.\n");
	for (;;) {
		fisherman_flag = (int)(2.0 * rand() / (RAND_MAX + 1.0));
		gun_pos = (int)(3.0 * rand() / (RAND_MAX + 1.0));
		if (fishes == 0)
			printf("���� ���� �����.\n");
		if (fishes > 0 && wash_flag == 0)
			printf("���� ���� �������.\n");
		printf("���������: 1) ������; 2) ����; 3) ���������;\n\?");
		do {
			scanf("%d", &tty_in);
		} while (tty_in < 1 || tty_in > 3);
		if ((tty_in - 1) == gun_pos) {
			printf
			    ("�� ����� ������ ��������� � �����. %d ��� ���������� ���.\n\n���� ��������\n",
			     rfc);
			return 0;
		}
		switch (tty_in) {
		case 1:
			if (fisherman_flag) {
				printf
				    ("�� ������� �������. %d ��� ���������� ���.\n\n���� ��������\n",
				     rfc);
				return 0;
			}
			fishes += 1;
			wash_flag = 0;
			break;
		case 2:
			if (fishes > 0) {
				printf("���أ ��� ��� ��������...\n");
				wash_flag = 1;
			} else
				printf("� ��� ������ ����!\n");
			break;
		case 3:
			if (fishes > 0 && wash_flag == 0)
				printf
				    ("�� �� ������ ��������� ������� ����!\n");
			if (fishes == 0)
				printf
				    ("�� �� ������ ��������� ������ � ����� �����!\n");
			if (fishes > 0 && wash_flag == 1) {
				printf("����-����, ����� �����!\n");
				rfc += fishes;
				fishes = 0;
				wash_flag = 0;
			}
			break;
		}
	}
	return 0;
}
