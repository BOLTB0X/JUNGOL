#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void solution(void) {
	int s, e;

	while (1) {
		scanf("%d %d", &s, &e);

		if (s >= 2 && e >= 2 && s <= 9 && e <= 9)
			break;
		else
			printf("INPUT ERROR!\n");
	}
	
	if (s < e) {
		for (int i = s; i <= e; ++i) {
			for (int j = 1; j <= 9; ++j) {
				printf("%d * %d = %2d   ", i, j, i * j);
				if (j % 3 == 0)
					printf("\n");
			}
			printf("\n");
		}
	}
	else {
		for (int i = s; i >= e; --i) {
			for (int j = 1; j <= 9; ++j) {
				printf("%d * %d = %2d   ", i, j, i * j);
				if (j % 3 == 0)
					printf("\n");
			}
			printf("\n");
		}
	}
}

int main(void) {
	solution();
	return 0;
}
