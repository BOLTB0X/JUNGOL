#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[10];

	for (int i = 0; i < 10; ++i)
		arr[i] = i + 1;

	for (int i = 0; i < 10; ++i)
		printf("%d ", arr[i]);

	return 0;
}