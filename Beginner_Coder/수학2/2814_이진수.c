#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int pow(int a, int b) {
	int res = 1;

	if (b == 0)
		return 1;

	for (int i = 0; i < b; ++i) {
		res *= a;
	}

	return res;
}

void solution(void) {
	char bin[31];
	scanf("%s", bin);

	int tot = 0;

	for (int i = 0; i < strlen(bin) ; ++i) {
		tot += (pow(2,strlen(bin) - 1 - i) * (bin[i] - '0'));
	}

	printf("%d\n", tot);
	return;
}

int main(void) {
	solution();
	return 0;
}
