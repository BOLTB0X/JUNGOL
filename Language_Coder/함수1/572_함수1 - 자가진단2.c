#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double get_area(int n) {
	double area = n * n * 3.14;
	return area;
}

int main(void) {
	int n;
	scanf("%d", &n);

	printf("%.2lf", get_area(n));

	return 0;
}