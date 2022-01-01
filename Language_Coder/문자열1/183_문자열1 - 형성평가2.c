#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char c1[101];
	scanf("%s", c1);
	
	for (int i = 0; i < 5; ++i)
		printf("%c", c1[i]);
	return 0;
}