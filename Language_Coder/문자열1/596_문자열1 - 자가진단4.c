#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[101];
	int start = 0;

	scanf("%s", str);
	scanf("%d", &start);

	if (start > strlen(str) - 1) 
		start = 0;
	else 
		start = strlen(str) - start;
	
	for (int i = strlen(str) - 1; i >= start; --i)
		printf("%c", str[i]);

	return 0;
}