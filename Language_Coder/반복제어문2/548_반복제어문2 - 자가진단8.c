#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	for (int i = 2; i < 5; ++i) {
		int num = i;
		for (int j = 1; j <= 5; ++j)
			printf("%d * %d = %2d   ", i, j, i * j);
		printf("\n");
	}


	return 0;
}