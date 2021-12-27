#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int a, b;
char str[1000001];

void solution(void) {
	while (1) {
		scanf("%d %s %d", &a, str, &b);
		if (a == 0) break;
	
		if (str[0] == '0') {
			printf("0\n");
			continue;
		}

		long long i, j;
		long long tot = 0;
		for (i = strlen(str) - 1, j = 1; i >= 0; i--, j *= a) {
			if (str[i] >= 'A')
				//정수로 변환
				str[i] = '9' + (str[i] - 'A') + 1;
			tot += j * (str[i] - '0');
		}

		char res[100];

		for (i = 0; tot > 0; tot /= b, ++i) {
			int tmp = tot % b;
			if (tmp > 9)
				res[i] = tmp - 10 + 'A';
			else
				res[i] = tmp + '0';
		}

		for (i = i - 1; i >= 0; --i)
			printf("%c", res[i]);
		printf("\n");
	}

	return;
}

int main(void) {
	solution();
	return 0;
}