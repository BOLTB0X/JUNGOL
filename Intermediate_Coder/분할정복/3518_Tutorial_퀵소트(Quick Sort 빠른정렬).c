#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int arr[10000];

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}

void print_arr(void) {
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

void quick_Sort(int start, int end) {
	if (start >= end)
		return;

	int i = start;
	int pivot = arr[end];

	for (int j = start; j < end; ++j) {
		if (arr[j] < pivot)
			swap(&arr[i++], &arr[j]);
	}
	swap(&arr[i], &arr[end]);

	print_arr();

	quick_Sort(start, i - 1);
	quick_Sort(i + 1, end);
	return;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	quick_Sort(0, n-1);

	return 0;
}