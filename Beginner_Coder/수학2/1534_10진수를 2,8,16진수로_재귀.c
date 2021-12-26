#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char num[17] = { '0', '1', '2', '3', 
				'4', '5', '6', '7', '8', 
				'9', 'A', 'B', 'C', 'D', 
				'E', 'F' };

void trans(int n, int b) {
	if (n != 0) {
		trans(n / b, b);
		printf("%c", num[n % b]);
	}

	return;
}

void solution(void) {
	int dec, type;

	scanf("%d %d", &dec, &type);

	trans(dec, type);
	return;
}

int main(void) {
	solution();
	return 0;
}