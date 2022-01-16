#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void solution(void) {
	char input[101] = { '\0',};
	
	strcpy(input, "Hong Gil Dong");

	printf("%s", input);

	return;
}

int main(void) {
	solution();

	return 0;
}