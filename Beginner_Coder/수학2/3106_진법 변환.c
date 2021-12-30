#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

long long a_to_dec(int a, char* str) {
	long long tot = 0;
	long long i, j;
	for (i = strlen(str) - 1, j = 1; i >= 0; --i, j *= a) {
		if (str[i] >= 'A')
			str[i] = '9' + (str[i] - 'A') + 1;
		tot += j * (str[i] - '0');
	}

	return tot;
}

void dec_to_b(int b, long long dec) {
	char res[100];
	long long i;
	for (i = 0; dec > 0; dec /= b, ++i) {
		if (dec % b > 9)
			res[i] = (dec % b) - 10 + 'A';
		else
			res[i] = (dec % b) + '0';
	}

	for (i = i - 1; i >= 0; --i)
		printf("%c", res[i]);
	printf("\n");

	return;
}

void solution(void) {
	int a, b;
	char str[1000001];

	while (1) {
		scanf("%d", &a);

		if (a == 0)
			break;

		scanf("%s %d", str, &b);

		if (str[0] == '0') {
			printf("0\n");
			continue;
		}

		//a진법을 10진법으로 한 뒤 10진법을 b진법으로
		dec_to_b(b,a_to_dec(a, str));
	}

	return;
}

int main(void) {
	solution();
	return 0;
}
