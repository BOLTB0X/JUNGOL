#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void solution(void) {
	char input1[101] = { '\0', };
	char input2[101] = { '\0', };

	scanf("%s %s", input1, input2);

	strncpy(input2, input1, 2);
	strncat(input2, input1, 2);

	printf("%s", input2);

	return;
}

int main(void) {
	solution();

	return 0;
}