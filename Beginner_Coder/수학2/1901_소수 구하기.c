#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int is_prime(int number) {
	if (number == 0 || number == 1)
		return 0;
	for (int i = 2; i * i <= number; ++i) {
		if (number % i == 0)
			return 0;
	}
	return 1;
}

void get_prime(int number) {
	int flag = 0;

	if (is_prime(number)) {
		printf("%d\n", number);
		return;
	}

	for (int i = 1; !flag; ++i) {
		if (is_prime(number - i)) {
			flag = 1;
			printf("%d ", number - i);
		}
		
		if (is_prime(number + i)) {
			flag = 1;
			printf("%d ", number + i);
		}
	}

	printf("\n");

	return;
}

void solution(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int m;
		scanf("%d", &m);
		get_prime(m);
	}

	return;
}

int main(void) {
	solution();
	return 0;
}