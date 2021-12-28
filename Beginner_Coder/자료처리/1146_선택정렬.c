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

	for (int i = 0; i < n - 1; ++i) {
		int min_val = 0x7fffffff;
		int flag = 0;
		for (int j = i; j < n; ++j) {
			if (min_val > arr[j]) {
				min_val = arr[j];
				idx = j;
			}
		}
		swap(&arr[i], &arr[idx]);
		print_arr(arr, n);
	}
	free(arr);
}

int main(void) {
	solution();
	return 0;
}