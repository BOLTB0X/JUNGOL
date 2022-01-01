#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[101];
	scanf("%s", str);

	for (int i = 0; i < 2; ++i) {
		printf("%s", str);
	}
	return 0;
}