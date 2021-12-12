#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
	
void triangle_type(int n, int m) {
	if (m == 1) {
		int number = 0, tmp;
		for (int i = 1; i <= n; ++i) {
			if (i % 2 == 0) {
				number += i;
				tmp = number;

				for (int j = 1; j <= i; ++j)
					printf("%d ", tmp--);
			}
			else {
				number += 1;
				for (int j = 1; j <= i; ++j)
					printf("%d ", number++);
				number--;
			}
			printf("\n");
		}
	}

	else if (m == 2) {
		int number = 0, tmp = 2 * n - 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j < 2 * i - 1; ++j)
				printf(" ");
			for (int j = 1; j <= tmp; ++j)
				printf("%d ", number);
			number++;
			tmp -= 2;
			printf("\n");
		}
	}

	else {
		for (int i = 1; i <= n / 2; ++i) {
			int number = 1;
			for (int j = 1; j <= i; ++j)
				printf("%d ",number++);
			printf("\n");
		}

		for (int i = 0; i < n / 2 + 1; ++i) {
			int number = 1;
			for (int j = 0; j <= n / 2 - i; ++j)
				printf("%d ", number++);
			printf("\n");
		}
	}

	return;
}

void solution(void) {
	int n, m;

	scanf("%d %d", &n, &m);

	if (n <= 0 || n > 100 || m <= 0 || m > 3 || n % 2 == 0) 
		printf("INPUT ERROR!\n");
	else
		triangle_type(n, m);

	return;
}

int main(void) {
	solution();
	return 0;
}