#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char c;

	scanf("%c", &c);

	if (c == 'A')
		printf("Excellent\n");
	else if (c == 'B')
		printf("Good\n");
	else if (c == 'C')
		printf("Usually\n");
	else if (c == 'D')
		printf("Effort\n");
	else if (c == 'F')
		printf("Failure\n");
	else
		printf("error\n");

	return 0;
}