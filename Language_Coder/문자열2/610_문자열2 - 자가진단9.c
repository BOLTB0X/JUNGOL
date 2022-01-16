#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void solution(void) {
	char words[5][21] = { "\0", };
	char tmp[21] = { "\0", };

	for (int i = 0; i < 5; ++i)
		scanf("%s", words[i]);

	for (int i = 0; i < 4; ++i) {
		for (int j = i + 1; j < 5; ++j) {
			if (strcmp(words[i], words[j]) < 0) {
				strcpy(tmp, words[i]);
				strcpy(words[i], words[j]);
				strcpy(words[j], tmp);
			}
		}
	}

	for (int i = 0; i < 5; ++i)
		printf("%s\n", words[i]);
	return;
}

int main(void) {
	solution();

	return 0;
}