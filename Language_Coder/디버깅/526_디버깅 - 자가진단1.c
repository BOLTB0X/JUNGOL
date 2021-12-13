#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	double a , b;

	scanf("%lf %lf", &a, &b);

	//출력을 int로 함

	printf("%d %d\n", (int)(a * b), ((int)a * (int)b));
	return 0;
}