#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int trans_dec(char bin[]) {
	int tmp = 0;

	for (int i = 0; i < strlen(bin); ++i) {
		tmp += (bin[i] - '0') * pow(2, strlen(bin) - 1 - i);
	}

	return tmp;
}

void solution(void) {
	char bin[31];
	int result = 0;
	scanf("%s", bin);

	result = trans_dec(bin);

	printf("%d\n", result);
	return;
}

int main(void) {
	solution();
	return 0;
}