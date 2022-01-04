#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, m;

	scanf("%d %d", &n, &m);
	if (n > m) {
		for (int i = 1; i <= 9; ++i) {
			for (int j = n; j >= m; --j) 
				printf("%d * %d = %2d   ", j, i, j * i);
			printf("\n");
		}
	}
	else {
		for (int i = 1; i <= 9; ++i) {
			for (int j = n; j <= m; ++j)
				printf("%d * %d = %2d   ", j, i, j * i);
			printf("\n");
		}
	}

	return 0;
}