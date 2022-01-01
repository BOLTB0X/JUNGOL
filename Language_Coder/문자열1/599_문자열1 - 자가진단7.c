#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[101];

	gets(str);
	str[100] = "\0";

	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			printf("%c", str[i]);
		else if (str[i] >= 'a' && str[i] <= 'z')
			printf("%c", str[i] - 32);
	}

	return 0;
}