#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int num, even = 0, odd = 0;

	while (1) {
		scanf("%d", &num);

		if (num == 0) {
			printf("odd : %d\n", odd);
			printf("even : %d\n", even);
			break;
		}
		else if (num % 2 == 0)
			even++;
		else
			odd++;
	}

	return 0;
}