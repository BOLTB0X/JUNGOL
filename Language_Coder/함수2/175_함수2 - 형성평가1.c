#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
	int n1 = *(int*)a;
	int n2 = *(int*)b;

	if (n1 > n2)
		return -1;
	else if (n1 < n2)
		return 1;
	else
		return 0;
}

void solution(void) {
	int n;
	scanf("%d", &n);

	int* arr = malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	qsort(arr, n, sizeof(int), compare);

	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	return;
}

int main(void) {
	solution();

	return 0;
}