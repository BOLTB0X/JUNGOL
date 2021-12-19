#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void solution(void) {
	char key[27];
	char enc[81];
	char dec[81];

	scanf("%s %[^\n]s", key, enc);

	int i;
	for (i = 0; i < strlen(enc)-1; ++i) {
		if (enc[i] == ' ') {
			dec[i] = ' ';
		}
		else if (enc[i] >= 65 && enc[i] <= 90)
			dec[i] = key[enc[i] - 65] - ' ';
		else if (enc[i] >= 97 && enc[i] <= 122)
			dec[i] = key[enc[i] - 97];
	}
	dec[i] = '\0';
	printf("%s\n", dec);

	return;
}

int main(void) {
	solution();
	return 0;
}