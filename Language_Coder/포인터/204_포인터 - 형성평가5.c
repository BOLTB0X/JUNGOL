#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void solution(void) {
	int n;
	scanf("%d", &n);
	int* arr = malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	int max_value = arr[0];
	int min_value = arr[0];

	for (int i = 1; i < n; ++i) {
		if (max_value < arr[i])
			max_value = arr[i];
		else if (min_value > arr[i])
			min_value = arr[i];
	}

	printf("max : %d\n", max_value);
	printf("min : %d\n", min_value);
	return;
}

int main(void) {
	solution();
	return 0;
}