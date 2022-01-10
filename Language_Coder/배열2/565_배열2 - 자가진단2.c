#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int occ[10] = { 0, };
	int val;

	for (int i = 0; i < 100; ++i) {
		scanf("%d", &val);

		if (val == 0)
			break;
		occ[(int)val / 10]++;
	}

	for (int i = 0; i < 10; ++i) {
		if (occ[i] > 0)
			printf("%d : %d\n", i, occ[i]);
	}
	return;
}