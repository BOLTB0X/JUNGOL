#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h> //atoi

void solution(void) {
	int a;
	char b[4];

	scanf("%d %s", &a, b);

	for (int i = strlen(b) - 1; i >= 0; --i) {
		printf("%d\n", a * (b[i] - '0'));
	}

	printf("%d\n", a * atoi(b));

	return;
}

int main(void) {
	solution();
	return 0;
}