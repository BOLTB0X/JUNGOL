#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int b, h;
	char ch;

	do {
		printf("Base = ");
		scanf("%d", &b);
		printf("Height = ");
		scanf("%d", &h);
		printf("Triangle width = %.1lf\n", (double)(b * h) / 2);
		
		printf("Continue? ");
		scanf(" %c", &ch);
	} while (ch == 'Y' || ch == 'y');


	return 0;
}