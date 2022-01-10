#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[100] = { 0, };
	int val, len = 2;

	arr[0] = 100;
	scanf("%d", &val);
	arr[1] = val;
	for (int i = 2; i < 100; ++i) {
		arr[i] = arr[i - 2] - arr[i - 1];
		len++;

		if (arr[i] < 0)
			break;
	}

	for (int i = 0; i < len; ++i) {
		printf("%d ", arr[i]);
	}
	return;
}