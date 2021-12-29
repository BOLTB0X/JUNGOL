#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;

	return;
}

void solution(void) {
	int n, step = 0;
	scanf("%d", &n);

	int* arr = malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	for (int i = 1; i < n; ++i) {
		for (int j = i; j > 0; --j) {
			if (arr[j] < arr[j - 1]) {
				swap(&arr[j], &arr[j - 1]);
				step++;
			}
			else
				break;
		}
	}

	printf("%d\n", step);
	free(arr);

	return;
}

int main(void) {
	solution();
	return 0;
}