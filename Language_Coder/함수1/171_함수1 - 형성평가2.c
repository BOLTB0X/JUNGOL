#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_call(int num) {
	int tot = 0;

	for (int i = 1; i <= num; ++i)
		tot += i;

	printf("%d", tot);
	return;
}

void solution(void) {
	int n;
	scanf("%d", &n);
	print_call(n);
	return;
}

int main(void) {
	solution();
	return 0;
}