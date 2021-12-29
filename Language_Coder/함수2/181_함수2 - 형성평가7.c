#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void get_res(double a) {
	double pi = 3.141592;
	printf("area = ");
	printf("%.3f\n", pi * a * a);

	return;
}

void solution(void) {
	double a;
	printf("radius : ");
	scanf("%lf", &a);

	get_res(a);

	return;
}

int main(void) {
	solution();

	return 0;
}