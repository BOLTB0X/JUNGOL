#define _CRT_SECURE_NO_WARNINIGS
#include <stdio.h>

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	if (n > m) {
		for (int i = m; i <= n; ++i)
			printf("%d ", i);
		printf("\n");
	}

	else {
		for (int i = n; i <= m; ++i)
			printf("%d ", i);
		printf("\n");
	}

	return 0;
}