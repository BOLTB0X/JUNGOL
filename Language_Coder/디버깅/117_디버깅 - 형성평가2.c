#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	double a, b, c;

	scanf("%lf %lf %lf", &a, &b, &c);

	//����� int�� ��

	printf("sum %d\n", (int)a + (int)b + (int)c);
	printf("avg %d\n", (int)((a + b + c) / 3));
	return 0;
}