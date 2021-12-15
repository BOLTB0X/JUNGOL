#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void is_prime_or_composite(int number) {
	if (number == 0 || number == 1) {
		printf("number one\n");
		return;
	}
	
	for (int i = 2; i * i <= number; ++i) {
		if (number % i == 0) {
			printf("composite number\n");
			return;
		}
	}
	printf("prime number\n");
	return;
}

void solution(void) {
	int arr[5];

	for (int i = 0; i < 5; ++i)
		scanf("%d", &arr[i]);
	
	for (int i = 0; i < 5; ++i)
		is_prime_or_composite(arr[i]);
	return;
}

int main(void) {
	solution();
	return 0;
}