#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a;
	int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	scanf("%d", &a);

	for (int i = 0; i < 12; ++i) {
		if (i == a - 1)
			printf("%d\n", arr[i]);
	}
	return 0;
}