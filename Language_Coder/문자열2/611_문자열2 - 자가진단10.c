#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void solution(void) {
	char str[21] = { '\0', };
	char tmp1[21] = { '\0', };
	char tmp2[21] = { '\0', };
	
	scanf("%s", str);
	
	
	printf("%d\n", atoi(str) * 2);
	printf("%.2f\n", atof(str));

	return;
}

int main(void) {
	solution();

	return 0;
}