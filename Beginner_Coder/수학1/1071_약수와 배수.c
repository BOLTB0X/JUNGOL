#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void solution(void) {
	int n, m;
	scanf("%d", &n);

	int* arr =(int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	scanf("%d", &m);
	int result1 = 0;
	int result2 = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] <= m && m % arr[i] == 0)
			result1 += arr[i];
		if (arr[i] >= m && arr[i] % m == 0)
			result2 += arr[i];
	}
	
	printf("%d\n", result1);
	printf("%d\n", result2);

	free(arr);
	return;
}

int main(void) {
	solution();
	return 0;
}