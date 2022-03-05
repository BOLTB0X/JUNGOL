#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int prime[2000005] = { 0, };

//에라토스테네체 이용
void eratos(int number) {
	prime[0] = prime[1] = 1;

	for (int i = 2; i * i <= number; ++i) {
		if (prime[i] == 1)
			continue;
		for (int j = i + i; j <= number; j += i)
			prime[j] = 1;
	}

	return;
}

int solution(int n, int m) {
	int result = 0;

	eratos(m);
	for (int i = n; i <= m; ++i) {
		if (prime[i] == 0)
			result++;
	}

	return result;
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	int ret = solution(n, m);
	printf("%d", ret);

	return 0;
}
