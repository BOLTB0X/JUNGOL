#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h>

int main(void) {
	int occ[10];
	int num1, num2, num3;
	scanf("%d %d %d", &num1, &num2, &num3);

	int tmp = num1 * num2 * num3;
	int div = 10;
	memset(occ, 0, sizeof(int) * 10);

	while (tmp > 0) {
		int rest = tmp % div;
		occ[rest]++;
		tmp /= div;
	}

	for (int i = 0; i < 10; ++i) {
		printf("%d\n", occ[i]);
	}
	return 0;
}