#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int arr[1000];
int tmp[1000];

void print_arr(int n) {
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	return;
}

void mergeSort(int n, int start, int end) {
	if (start >= end)
		return;

	int mid = (start + end) / 2;
	mergeSort(n, start, mid);
	mergeSort(n, mid + 1, end);

	int i = start, j = mid + 1;
	for (int k = start; k <= end; ++k) {
		if (j > end)
			tmp[k] = arr[i++];
		else if (i > mid)
			tmp[k] = arr[j++];
		else if (arr[i] <= arr[j])
			tmp[k] = arr[i++];
		else
			tmp[k] = arr[j++];
	}
	/*
	int k = start;
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}

	while (i <= mid)
		tmp[k++] = arr[i++];
	while (j <= end)
		tmp[k++] = arr[j++];
	*/
	for (int i = start; i <= end; ++i)
		arr[i] = tmp[i];

	print_arr(n);
	return;
}

int main(void) {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	mergeSort(n, 0, n - 1);
}