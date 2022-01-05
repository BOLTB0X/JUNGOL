#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char arr[11];

	for (int i = 1; i <= 10; ++i)
		scanf(" %c", &arr[i]);

	for (int i = 1; i < 10; i += 3)
		printf("%c ", arr[i]);

	return 0;
}