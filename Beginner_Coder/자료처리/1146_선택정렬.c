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
	int n;
	scanf("%d", &n);

	int* arr = malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	int min_idx;
	for (int i = 0; i < n - 1; ++i) {
		int min_idx = i;
		for (int j = i; j < n; ++j) {
			if (arr[min_idx] > arr[j]) 
				min_idx = j;
		}
		swap(&arr[i], &arr[min_idx]);
		print_arr(arr, n);
	}
	free(arr);
}

int main(void) {
	solution();
	return 0;
}
