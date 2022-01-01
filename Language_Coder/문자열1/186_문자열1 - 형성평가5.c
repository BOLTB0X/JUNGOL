#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str1[101] = { '\0', };
	char str2[101] = { '\0', };

	scanf("%s", str1);
	scanf(" %s", str2);

	if (strlen(str1) > strlen(str2))
		printf("%d", strlen(str1));
	else
		printf("%d", strlen(str2));

	return 0;
}