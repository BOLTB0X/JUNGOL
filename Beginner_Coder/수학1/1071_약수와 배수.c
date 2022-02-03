#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, m;
	int* arr;
	int res1 = 0, res2 = 0;

	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	scanf("%d", &m);

	for (int i = 0; i < n; ++i) {
		if (arr[i] <= m && m % arr[i] == 0)
			res1 += arr[i];
		if (arr[i] >= m && arr[i] % m == 0)
			res2 += arr[i];
	}

	printf("%d\n", res1);
	printf("%d\n", res2);

	free(arr);
	return 0;
}
