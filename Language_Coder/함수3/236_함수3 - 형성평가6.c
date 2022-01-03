#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int recur(int n) {
	if (n == 0)
		return 1;

	else if (n % 10 == 0)
		return 1 * recur(n / 10);
	else if (n % 10 != 0)
		return n % 10 * recur(n / 10);

}

void solution(void) {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);


	printf("%d", recur(a*b*c));
	return;
}

int main(void) {
	solution();
	return 0;
}
