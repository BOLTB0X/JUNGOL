#define _CRT_SECURE_NO_WARNINIGS
#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	double tot = 0;
	for (int i = 1; i <= n; ++i) {
		int val;
		scanf("%d", &val);
		tot += val;
	}

	printf("%.2lf\n", (double)tot/n);

	return 0;
}