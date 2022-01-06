#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int tot1 = 0;
	int tot2 = 0;

	for (int i = 0; i < 10; ++i) {
		int val;
		scanf("%d", &val);
		if (i % 2 == 0) {
			tot2 += val;
		}
		else
			tot1 += val;
	}

	printf("sum : %d\n", tot1);
	printf("avg : %.1lf", (double)tot2 / 5);

	return 0;
}