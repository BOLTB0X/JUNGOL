#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[101];

	fgets(str,101,stdin);
	str[100] = "\0";
	int cnt = 1;
	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] == ' ')
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}