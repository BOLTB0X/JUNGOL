#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void get_reverse_and_tot(long long int n) {
	long long int tot = 0, reverse_value = 0;

	while (n) {
		reverse_value = (reverse_value * 10) + (n % 10);
		tot += (n % 10);
		n /= 10;
	}

	printf("%lld %lld\n", reverse_value, tot);
	return;
}

void solution(void) {
	while (1) {
		long long int n;
		scanf("%lld", &n);

		if (n == 0)
			break;
		get_reverse_and_tot(n);
	}

	return;
}

int main(void) {
	solution();
	return 0;
}