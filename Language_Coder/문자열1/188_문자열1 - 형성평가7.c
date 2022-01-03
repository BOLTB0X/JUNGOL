#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void solution(void) {
	char str[101] = { '\0', };
	
	fgets(str,101,stdin);
	int i, idx = 1;

	printf("%d. ", idx++);
	for (i = 0; i < strlen(str); ++i) {
		if (str[i] != ' ')
			printf("%c", str[i]);
		else
			printf("\n%d. ", idx++);
	}

	return;
}

int main(void) {
	solution();

	return 0;
}