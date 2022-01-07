#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[100];

int main(void) {
	int cnt = 0;
	for (int i = 0; i < 100; ++i) {
		scanf("%d", &arr[i]);
		if (arr[i] == -1)
			break;
		cnt++;
	}

	if (cnt < 3) {
		for (int i = 0; i < cnt; ++i)
			printf("%d ", arr[i]);
	}
	else {
		for (int i = cnt - 3; i < cnt; ++i) {
			printf("%d ", arr[i]);
		}
	}

	return 0;
}