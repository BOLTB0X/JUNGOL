#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long factorial(int n) {
	if (n == 1) {
		printf("%d! = %d\n", n, n);
		return 1;
	}
	else {
		printf("%d! = %d * %d!\n", n, n, n - 1);
		return n * factorial(n - 1);
	}

}

void solution(void) {
	int n;
	scanf("%d", &n);
	long long int ret = factorial(n);

	printf("%lld\n", ret);
	return;
}

int main(void) {
	solution();
	return 0;
}