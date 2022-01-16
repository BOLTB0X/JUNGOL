#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void solution(void) {
	char input[101] = { '\0', };

	scanf("%s",input);

	if (strstr(input, "c"))
		printf("Yes ");
	else
		printf("No ");

	if (strstr(input, "ab"))
		printf("Yes ");
	else
		printf("No");

	return;
}

int main(void) {
	solution();

	return 0;
}