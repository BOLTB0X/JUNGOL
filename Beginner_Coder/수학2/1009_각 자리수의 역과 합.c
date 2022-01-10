#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void get_reverse_and_tot(unsigned long long number) {
	unsigned long long tot = 0, reverse = 0;

	while (number > 0) {
		reverse = (reverse * 10) + (number % 10);
		tot += (number % 10);
		number /= 10;
	}

	printf("%lld %lld\n", reverse, tot);
	return;
}

void solution(void) {
	while (1) {
		unsigned long long n;
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
