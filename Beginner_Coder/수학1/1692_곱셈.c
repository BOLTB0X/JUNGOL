#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 

int main(void) {
	int num1; 
	char num2[4] = { 0, };
	int answer = 0;
	scanf("%d %s", &num1, num2);

	for (int i = strlen(num2) - 1, j = 1; i >= 0; --i, j *= 10) {
		printf("%d\n", (num2[i] - '0') * num1);
		answer += (j * (num2[i] - '0') * num1);
	}
	
	printf("%d", answer);

	return 0;
}
