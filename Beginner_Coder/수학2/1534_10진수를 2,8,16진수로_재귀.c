#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char number[17] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

void trans(int dec, int t) {
	if (dec != 0) {
		trans(dec / t, t);
		printf("%c", number[dec % t]);
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
