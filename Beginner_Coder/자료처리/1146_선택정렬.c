#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 스와핑
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

void solution(int n, int* arr) {
	for (int i = 0; i < n - 1; ++i) {
		int min_idx = i;
		for (int j = i; j < n; ++j) {
			// 첫 피벗값보다 작은 값을 발견하면
			if (arr[min_idx] > arr[j])
				min_idx = j;
		}
		// 교체
		swap(&arr[i], &arr[min_idx]);
		// 출력
		print_arr(arr, n);
	}

	return;

}

int main(void) {
	int n;
	scanf("%d", &n);

	int* arr = malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	solution(n, arr);
	free(arr);
	return 0;
}
