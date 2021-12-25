#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int num, tot = 0, cnt = 0;

	do {
		scanf("%d", &num);

		if (num >= 0 && num <= 100) {
			tot += num;
			cnt++;
		}
		else
			break;

	} while (1);
	printf("sum : %d\n", tot);
	printf("avg : %.1lf\n", (double)tot/cnt);

	return 0;
}