#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		int num = i;
		for (int j = 0; j < m; ++j) {
			printf("%d ", num);
			num += i;
		}
		printf("\n");
	}

	return 0;
}