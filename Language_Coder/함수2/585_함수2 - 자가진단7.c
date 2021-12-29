#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[10];

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;

	return;
}

void print_arr(void) {
	for (int i = 0; i < 10; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	return;
}

void bubble_Sort(void) {
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10 - i; j++) {
			if (arr[j] < arr[j + 1]) 
				swap(&arr[j], &arr[j + 1]);
		}
		print_arr();
	}
}

void solution(void) {
	for (int i = 0; i < 10; ++i)
		scanf("%d", &arr[i]);

	bubble_Sort();
}

int main(void) {
	solution();
	return 0;
}