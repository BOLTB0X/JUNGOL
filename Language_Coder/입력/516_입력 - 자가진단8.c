#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	double a, b;
	char c;
	scanf("%lf %lf %c", &a, &b, &c);

	printf("%.2f\n", a);
	printf("%.2f\n", b);
	printf("%c\n",c);

	return 0;
}