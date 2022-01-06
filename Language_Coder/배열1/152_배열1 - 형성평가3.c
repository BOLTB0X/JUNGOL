#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[10];

int main(void) {
	int even = 0, odd = 0;

	for (int i = 0; i < 10; ++i) {
		scanf("%d", &arr[i]);

		if (i % 2 == 0)
			odd += arr[i];
		else
			even += arr[i];
	}

	printf("odd : %d\n", odd);
	printf("even : %d\n", even);

	return 0;
}