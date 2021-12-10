#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	double a, b, c;

	scanf("%lf %lf %lf", &a, &b, &c);

	printf("%.3lf\n", a);
	printf("%.3lf\n", b);
	printf("%.3lf\n", c);

	return 0;
}