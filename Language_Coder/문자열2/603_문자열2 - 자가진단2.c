#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void solution(void) {
	char input[101];

	fgets(input, 101, stdin);
	int flag = 1;
	
	for (int i = 0; i < strlen(input); ++i) {
		if (input[i] == ' ') {
			if (flag == 1) {
				printf("\n");
				flag = 0;
			}
			else
				flag = 1;
		}
		else if (flag == 1)
			printf("%c", input[i]);
	}

	return;
}

int main(void) {
	solution();

	return 0;
}
