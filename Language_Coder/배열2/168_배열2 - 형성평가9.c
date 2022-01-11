#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[11][11];

	for (int i = 0; i < 11; ++i) {
		for (int j = 0; j < 11; ++j)
			arr[i][j] = 0;
	}

	int n;
	scanf("%d", &n);
	arr[1][1] = 1;

	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}
	
	for (int i = n; i >= 1; --i) {
		for (int j = 1; j <= i; ++j) {
			if (arr[i][j] > 0)
				printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	

	return;
}