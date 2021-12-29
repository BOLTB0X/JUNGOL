#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;

	return;
}

int compare(const void* a, const void* b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 > num2)
		return -1;
	if (num1 < num2)
		return 1;
	return 0;
}

void insert_Sort(int* arr, int len) {
	int idx;

	for (int i = 1; i < len; ++i) {
		for (int j = i; j > 0; --j) {
			if (arr[j] > arr[j - 1])
				swap(&arr[j], &arr[j - 1]);
			else
				break;
		}
	}
}

void solution(void) {
	int n;
	scanf("%d", &n);

	int* arr = malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	qsort(arr, n, sizeof(int), compare);
	//insert_Sort(arr, n);

	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	return;
}

int main(void) {
	solution();
	return 0;
}