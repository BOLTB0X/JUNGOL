#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[10];

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;

	return;
}

void insert_Sort(void) {
	for (int i = 1; i < 10; ++i) {
		for (int j = i; j > 0; --j) {
			if (arr[j] > arr[j - 1])
				swap(&arr[j], &arr[j - 1]);
			else
				break;
		}
	}
}

int main(void) {
	for (int i = 0; i < 10; ++i) {
		scanf("%d", &arr[i]);
	}
	
	insert_Sort();
	for (int i = 0; i < 10; ++i) {
		printf("%d ", arr[i]);
	}

	return 0;
}