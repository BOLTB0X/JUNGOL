#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int get_cnt(double a, double b) {
	int cnt = 0;
	
	if (a > b) {
		double tmp = a;
		a = b;
		b = tmp;
	}
	
	//ÀÛÀº ¼ö
	a = sqrt(a) > (int) sqrt(a) ? ((int)sqrt(a) + 1) : (int)sqrt(a);
	b = (int)sqrt(b);

	for (; a <= b; ++a)
		cnt++;

	return cnt;
}

void solution(void) {
	double a, b;
	scanf("%lf %lf", &a, &b);

	printf("%d\n", get_cnt(a, b));

	return;
}

int main(void) {
	solution();

	return 0;
}