#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void solution(void) {
	char input1[21] = { '\0', };
	char input2[21] = { '\0', };
	char input3[21] = { '\0', };
	char tmp[21] = { '\0', };

	scanf("%s %s %s", input1, input2, input3);

	strcpy(tmp, (strcmp(input1, input2) < 0 ? input1 : input2));
	printf("%s", strcmp(tmp, input3) < 0 ? tmp : input3);
	return;
}

int main(void) {
	solution();

	return 0;
}