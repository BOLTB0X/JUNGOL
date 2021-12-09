#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

void triangle_type(int h, int t) {
	if (t == 1) {
		for (int i = 0; i < h / 2; ++i) {
			for (int j = 0; j <= i; ++j)
				printf("*");
			printf("\n");
		}

		for (int i = 0; i < h / 2 + 1; ++i) {
			for (int j = h / 2 - i; j >= 0; --j)
				printf("*");
			printf("\n");
		}
	}

	else if (t == 2) {
		for (int i = 0; i < h / 2; ++i) {
			for (int j = 0; j < h / 2 - i; ++j)
				printf(" ");
			for (int j = 0; j <= i; ++j)
				printf("*");
			printf("\n");
		}

		for (int i = 0; i < h / 2 + 1; ++i) {
			for (int j = 0; j < i; ++j)
				printf(" ");
			for (int j = h / 2 - i; j >= 0; --j)
				printf("*");
			printf("\n");
		}
	}

	else if (t == 3) {
		for (int i = 0; i < h / 2; ++i) {
			for (int j = 0; j < i; ++j)
				printf(" ");
			for (int j = 0; j < h - i * 2; ++j)
				printf("*");
			printf("\n");
		}

		for (int i = 0; i < h / 2 + 1; ++i) {
			for (int j = 0; j < h / 2 - i; ++j)
				printf(" ");
			for (int j = 0; j <= i * 2; ++j)
				printf("*");
			printf("\n");
		}
	}

	else if (t == 4) {
		for (int i = 0; i < h / 2; ++i) {
			for (int j = 0; j < i; ++j)
				printf(" ");
			for (int j = 0; j <= h / 2 - i; ++j)
				printf("*");
			printf("\n");
		}

		for (int i = 0; i < h / 2 + 1; ++i) {
			for (int j = 0; j < h / 2; ++j)
				printf(" ");
			for (int j = 0; j <= i; ++j)
				printf("*");
			printf("\n");
		}
	}
	else
		printf("INPUT ERROR!\n");

	return;
}

void solution(void) {
	int n, m;

	scanf("%d %d", &n, &m);

	if (n <= 0 || n > 100 || n % 2 == 0)
		printf("INPUT ERROR!");
	else
		triangle_type(n, m);

	return;
}

int main(void) {
	solution();
	return 0;
}