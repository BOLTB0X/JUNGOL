#include <stdio.h>

int main(void) {
	int n, tot = 0;
	scanf("%d", &n);

	for (int i = n; i <= 100; ++i) {
		tot += i;
	}

	printf("%d", tot);
	return 0;
}