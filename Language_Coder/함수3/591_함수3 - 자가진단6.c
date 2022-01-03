#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int recur(int n) {
	if (n <= 1)
		return 1;
	return recur(n / 2) + recur(n - 1);
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
