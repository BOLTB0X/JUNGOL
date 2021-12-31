#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int recur(int n) {
	if (n == 0)
		return 0;
	return (n % 10) * (n % 10) + recur(n / 10);
}

void solution(void) {
	int n;
	scanf("%d", &n);

	printf("%d", recur(n));
	return;
}

int main(void) {
	solution();
	return 0;
}