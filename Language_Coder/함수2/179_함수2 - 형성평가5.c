#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void get_res(double a, double b, double c) {
	printf("%0.f\n", floor((a + b + c) / 3 + 0.5));
	double tot = floor(a + 0.5) + floor(b + 0.5) + floor(c + 0.5);
	printf("%0.f\n", floor(tot / 3 + 0.5));

	return ;
}

void solution(void) {
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);

	get_res(a, b, c);

	return;
}

int main(void) {
	solution();

	return 0;
}