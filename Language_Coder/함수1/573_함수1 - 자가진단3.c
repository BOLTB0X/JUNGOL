#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_sq(int n) {
	int number = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", ++number);
		}
		printf("\n");
	}
	return;
}

int main(void) {
	int n;
	scanf("%d", &n);

	print_sq(n);

	return 0;
}