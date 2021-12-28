#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_sq(int num) {

	for (int i = 1; i <= num; ++i) {
		int number = 0;
		for (int j = 1; j <= num; ++j) {
			printf("%d ", (number+=i));
		}
		printf("\n");
	}
	return;
}

void solution(void) {
	int n;
	scanf("%d", &n);
	print_sq(n);
	return;
}

int main(void) {
	solution();
	return 0;
}