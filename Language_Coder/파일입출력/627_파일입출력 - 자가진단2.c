#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	double n, tot = 0;
	for (int i = 0; i < 10; ++i) {
		scanf("%lf", &n);
		if (i == 0 || i == 9)
			tot += n;
	}

	printf("%.1lf", (double)tot/2);
	return 0;
}