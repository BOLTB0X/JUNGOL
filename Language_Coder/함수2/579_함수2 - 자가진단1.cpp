#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}

void insert_Sort(int n, int* arr) {
	for (int i = 1; i < n; ++i) {
		for (int j = i; j >= 1; --j) {
			if (arr[j] > arr[j - 1])
				swap(&arr[j], &arr[j - 1]);
			else
				break;
		}
	}
}

int main(void) {
	int n, arr[11];

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	//»ðÀÔÁ¤·Ä
	insert_Sort(n, arr);

	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	return 0;
}