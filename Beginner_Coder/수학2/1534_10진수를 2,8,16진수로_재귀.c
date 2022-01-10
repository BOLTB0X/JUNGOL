#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char numbers[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

void trans_num(int dec, int type) {
	if (dec == 0)
		return;
	trans_num(dec / type, type);
	printf("%c", numbers[dec % type]);
}

void solution(void) {
	int dec, type;

	scanf("%d %d", &dec, &type);

	trans_num(dec, type);
}

int main(void) {
	solution();
	return 0;
}
