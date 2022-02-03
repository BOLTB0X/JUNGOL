#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, k, idx = 0;
	scanf("%d %d", &n, &k);

	int* arr = malloc(sizeof(int) * (n + 1));

	for (int i = 1; i <= n; ++i) {
		if (n % i == 0)
			arr[idx++] = i;
	}

	if (idx < k)
		printf("0\n");
	else
		printf("%d\n", arr[k - 1]);

	free(arr);
	return 0;
}
