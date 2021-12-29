#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;

	return;
}

void bubble_Sort(int arr[]) {
	for (int i = 6; i >= 4; --i) {
		for (int j = 0; j < 6; ++j) {
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}

	return;
}

void solution(void) {
	int arr[7];
	for (int i = 0; i < 7; ++i) 
		scanf("%d", &arr[i]);

	bubble_Sort(arr);

	for (int i = 0; i < 7; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	return;
}

int main(void) {
	solution();

	return 0;
}