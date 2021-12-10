#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	double a;
	printf("yard? ");
	scanf("%lf", &a);

	printf("%.1lfyard = %.1lfcm\n", a, (double)91.44*a);

	return 0;
}