#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char num[100001];

void trans(int n, int b) {
	if (b == 16) {
		for (int i = 0; n > 0;n/=b,i++) {
			int tmp = n % b;
			if (tmp > 9)
				num[i] = tmp - 10 + 'A';
			else
				num[i] = tmp + '0';
		}
	}

	else {
		for (int i = 0; n > 0; n /= b, i++) {
			int tmp = n % b;
			num[i] = tmp + '0';
		}
	}

	for (int i = strlen(num) - 1; i >= 0; --i)
		printf("%c", num[i]);

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