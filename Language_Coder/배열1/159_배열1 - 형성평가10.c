#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[100] = { 0, };

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;

	return;
}

void insert_Sort(int len) {
	for (int i = 1; i < len; ++i) {
		for (int j = i; j > 0; --j) {
			if (arr[j] > arr[j - 1]) 
				swap(&arr[j], &arr[j - 1]);
		}
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}

	insert_Sort(n);
	for (int i = 0; i < n; ++i)
		printf("%d\n", arr[i]);

	return 0;
}