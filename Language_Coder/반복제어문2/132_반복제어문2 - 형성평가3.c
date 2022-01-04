#define _CRT_SECURE_NO_WARNINIGS
#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);

	int tot = 0;
	for (int i = 1; i <= n; ++i) {
		if (i % 5 == 0)
			tot += i;
	}

	printf("%d\n", tot);

	return 0;
}