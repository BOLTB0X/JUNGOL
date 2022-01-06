#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char arr[10];

int main(void) {
	for (int i = 9; i >= 0; --i) {
		scanf(" %c", &arr[i]);
	}

	for (int i = 0; i < 10; ++i) {
		printf("%c ", arr[i]);
	}

	return 0;
}