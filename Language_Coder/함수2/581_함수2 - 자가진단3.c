#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void print_answer(int a, int b, double c, double d) {
	printf("%d\n", (abs(a) > abs(b) ? a : b));
	printf("%.2lf\n", (fabs(c) < fabs(d) ? c : d));

	return;
}

void solution(void) {
	int a, b;
	double c, d;
	scanf("%d %d", &a, &b);
	scanf("%lf %lf", &c, &d);

	print_answer(a, b, c, d);
	return;
}

int main(void) {
	solution();
	return 0;
}