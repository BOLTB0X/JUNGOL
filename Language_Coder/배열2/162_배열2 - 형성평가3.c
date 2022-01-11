#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[10] = { 0, };
	int a, b;
	scanf("%d %d", &a, &b);

	arr[0] = a;
	arr[1] = b;

	for (int i = 2; i < 10; ++i) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10;
	}

	for (int i = 0; i < 10; ++i) {
		printf("%d ", arr[i]);
	}

	return;
}