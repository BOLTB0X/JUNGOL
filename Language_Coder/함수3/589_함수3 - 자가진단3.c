#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int recur(int n) {
	if (n == 0)
		return 0;
	return n + recur(n - 1);
}

void solution(void) {
	int n;
	scanf("%d", &n);

	printf("%d\n", recur(n));
	return;
}

int main(void) {
	solution();
	return 0;
}
