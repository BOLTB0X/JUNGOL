#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char num[100001];

void trans(int n, int b) {
	//16진수
	if (b == 16) {
		for (int i = 0; n > 0;n/=b,i++) {
			int tmp = n % b;
			if (tmp > 9)
				num[i] = tmp - 10 + 'A';
			else
				num[i] = tmp + '0';
		}
	}
	//8진수, 2진수
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
	/* while문 버전
	int tmp = dec;
	int idx = 0;
	while (tmp > 0) {
		if (type == 16) {
			if (tmp % 16 > 9)
				result[idx++] = (tmp % 16) - 10 + 'A';
			else
				result[idx++] = (tmp % 16) + '0';
			tmp /= 16;
		}
		else {
			result[idx++] = (tmp % type) + '0';
			tmp /= type;
		}
	}

	for (int i = idx - 1; i >= 0; --i)
		printf("%c", result[i]);
	*/
	trans(dec, type);
	return;
}

int main(void) {
	solution();
	return 0;
}
