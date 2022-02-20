#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hanoi(int n, int from, int to, int other) {
	if (n == 1) {
		printf("%d : %d -> %d\n", 1, from, to);
		return;
	}

	hanoi(n - 1, from, other, to);
	printf("%d : %d -> %d\n", n, from, to);
	hanoi(n - 1, other, to, from);

	return;
}

void solution(int n) {
	//하노이
	hanoi(n, 1, 3, 2);

	return;
}

int main(void) {
	int n;

	scanf("%d", &n);

	solution(n);
	return 0;
}
