#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char arr[5];

int main(void) {
	for (int i = 0; i < 5; ++i) {
		scanf("%d", &arr[i]);
	}

	printf("%d", arr[0] + arr[2] + arr[4]);

	return 0;
}