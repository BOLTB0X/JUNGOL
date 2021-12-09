#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b;
	while (1) {
		scanf("%d %d", &a, &b);
		if (a >= 2 && b >= 2 && a <= 9 && b <= 9)
			break;
		else
			printf("INPUT ERROR!\n");
	}
	
	if (a < b) {
		for (int i = 1; i <= 9; ++i) {
			for (int j = a; j <= b; ++j) {
				printf("%d * %d = %2d   ", j, i, j * i);
			}
			printf("\n");
		}
	}

	else {
		for (int i = 1; i <= 9; ++i) {
			for (int j = a; j >= b; --j) {
				printf("%d * %d = %2d   ", j, i, j * i);
			}
			printf("\n");
		}
	}

	return 0;
}