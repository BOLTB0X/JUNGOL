#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*
double sqrt(double a) {
	double x = 2;
	for (int i = 0; i < 10; i++)
		x = (x + (a / x)) / 2;

	return x;
}
*/

double get_radius(int a) {
	return sqrt(a/3.14);
}

void solution(void) {
	int a;

	scanf("%d", &a);
	printf("%.2lf\n", get_radius(a));
	return;
}

int main(void) {
	solution();
	return 0;
}