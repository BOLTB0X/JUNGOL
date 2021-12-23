#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int prime[2000005];

void eratos(int number) {
	prime[0] = prime[1] = 1;

	for (int i = 2; i * i <= number; ++i) {
		if (prime[i] == 0) {
			for (int j = i * i; j <= number; j += i) {
				prime[j] = 1;
			}
		}
	}

	return;
}

void solution(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	int result = 0;
	memset(prime, 0, sizeof(int) * 2000005);

	eratos(m);
	for (int i = n; i <= m; ++i) {
		if (prime[i] == 0)
			result++;
	}

	printf("%d\n", result);
	return 0;
}

int main(void) {
	solution();

	return 0;
}