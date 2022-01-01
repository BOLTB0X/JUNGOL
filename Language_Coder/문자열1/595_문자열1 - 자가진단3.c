#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[101] = "Hong Gil Dong";

	for (int i = 3; i <= 6; ++i) {
		printf("%c", str[i]);
	}
	return 0;
}