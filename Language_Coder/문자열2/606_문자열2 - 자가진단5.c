#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void solution(void) {
	char input[101] = { '\0', };
	scanf("%s", input);

	strcat(input, "fighting");

	printf("%s", input);

	return;
}

int main(void) {
	solution();

	return 0;
}