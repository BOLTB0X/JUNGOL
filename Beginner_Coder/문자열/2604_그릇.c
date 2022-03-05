#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[101];
	int result = 10;

	scanf("%s", str);
	//문자열 탐색
	for (int i = 1; i < strlen(str); ++i) {
		if (str[i - 1] == str[i])
			result += 5;
		else
			result += 10;
	}

	printf("%d\n", result);
	return 0;
}
