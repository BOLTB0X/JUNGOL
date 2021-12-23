#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
	
	return;
}

void quick_Sort(int* arr, int n, int start, int end) {
	if (start >= end)
		return;
	int left = start, right = end, pivot = start;

	while (left <= right) {
		while (left <= end && arr[left] >= arr[pivot])
			left++;
		while (right > start && arr[right] < arr[pivot])
			right--;

		if (left > right)
			swap(&arr[pivot], &arr[right]);
		else
			swap(&arr[left], &arr[right]);
	}

	quick_Sort(arr, n, start, right - 1);
	quick_Sort(arr, n, right + 1, end);
}

void solution(void) {
	int n;
	scanf("%d", &n);
	int* arr = malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i) 
		scanf("%d", &arr[i]);

	//내림차순 정렬
	quick_Sort(arr, n, 0, n - 1);

	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	free(arr);
	return;
}

int main(void) {
	solution();
	return 0;
}