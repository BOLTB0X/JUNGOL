#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void recur(int n) {
	if (n == 0)
		return;
	printf("recursive\n");
	recur(n - 1);
}

void solution(void) {
	int n;
	scanf("%d", &n);

	recur(n);
	return;
}

int main(void) {
	solution();
	return 0;
}