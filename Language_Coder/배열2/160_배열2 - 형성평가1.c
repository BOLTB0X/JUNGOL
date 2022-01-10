#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[7] = { 0, };

	int val;
	for (int i = 0; i < 10; ++i) {
		scanf("%d", &val);

		arr[val]++;
	}

	for (int i = 1; i <= 6; ++i)
		printf("%d : %d\n", i, arr[i]);

	return;
}