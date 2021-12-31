#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void recur(int n, int tot, int cnt, int num) {
	if (cnt == n) {
		printf("%d\n", tot);
		return;
	}
	recur(n, tot + num, cnt + 1, num + 1);
	return;
}

void solution(void) {
	int n;
	scanf("%d", &n);

	recur(n, 0, 0, 1);
	return;
}

int main(void) {
	solution();
	return 0;
}