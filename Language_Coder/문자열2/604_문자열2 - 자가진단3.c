#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void solution(void) {
	char input[11][21];
	char target;
	
	for (int i = 0; i < 10; ++i) {
		scanf("%s", input[i]);
	}

	scanf(" %c", &target);
	
	for (int i = 0; i < 10; ++i) {
		int idx = strlen(input[i]) - 1;
		if (input[i][idx] == target)
			printf("%s\n", input[i]);
	}


	return;
}

int main(void) {
	solution();

	return 0;
}