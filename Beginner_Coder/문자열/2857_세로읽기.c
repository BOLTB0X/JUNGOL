#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char pane[5][16];

void solution(void) {
	for (int i = 0; i < 5; ++i)
		memset(pane[i], '\0', sizeof(char) * 16);

	for (int i = 0; i < 5; ++i) 
		scanf("%s", pane[i]);
	

	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (pane[j][i] == '\0')
				continue;
			printf("%c", pane[j][i]);
		}
	}
	return;
}

int main(void) {
	solution();
	return 0;
}