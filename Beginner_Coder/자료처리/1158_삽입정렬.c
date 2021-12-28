#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;

	return;
}

void print_arr(int* arr, int len) {
	for (int i = 0; i < len; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return;
}

void solution(void) {
	int n, idx;
	scanf("%d", &n);

	int* arr = malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	for (int i = 1; i < n; ++i) {
		for (int j = i; j > 0; --j) {
			if (arr[j] < arr[j - 1])
				swap(&arr[j], &arr[j - 1]);
			else
				break;
		}
		print_arr(arr, n);
	}
	free(arr);
}

int main(void) {
	solution();
	return 0;
}