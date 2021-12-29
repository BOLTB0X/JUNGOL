#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int get_res(int a) {
	int res = 1;

	if (a == 0)
		return 1;
	for (int i = 0; i < a; ++i)
		res *= 2;
	return res;
}

void solution(void) {
	int a;
	scanf("%d", &a);

	printf("%d\n", get_res(a));

	return;
}

int main(void) {
	solution();

	return 0;
}