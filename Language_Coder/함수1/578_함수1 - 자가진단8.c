#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_gugudan(int a, int b) {
	if (a < b) {
		for (int i = a; i <= b; ++i) {
			printf("== %ddan ==\n", i);
			for (int j = 1; j <= 9; ++j) {
				printf("%d * %d = %2d\n", i, j, i * j);
			}
			printf("\n");
		}
	}
	else {
		for (int i = b; i <= a; ++i) {
			printf("== %ddan ==\n", i);
			for (int j = 1; j <= 9; ++j) {
				printf("%d * %d = %2d\n", i, j, i * j);
			}
			printf("\n");
		}
	}
}

void solution(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	print_gugudan(a, b);
	return;
}

int main(void) {
	solution();
	return 0;
}