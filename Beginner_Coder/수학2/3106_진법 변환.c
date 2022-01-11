#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

long long trans_num(int type, char* n) {
	long long tot = 0;

	long long i, j;
	for (i = strlen(n) - 1, j = 1; i >= 0; --i, j *= type) {
		if (n[i] >= 'A') 
			n[i] = '9' + (n[i] - 'A') + 1;
		tot += j * (n[i] - '0');
	}

	return tot;
}

void trans_type2(int type, long long n) {
	char num[1001];

	long long idx = 0;
	while (n > 0) {
		if (n % type > 9)
			num[idx++] = (n % type) - 10 + 'A';
		else
			num[idx++] = (n % type) + '0';
		n /= type;
	}
	num[idx] = '\0';

	for (long long i = strlen(num) - 1; i >= 0; --i) {
		printf("%c", num[i]);
	}
	printf("\n");
	return;
}

void solution(void) {
	int type1, type2;
	char num[1000001];

	while (1) {
		scanf("%d", &type1);

		if (type1 == 0)
			break;

		scanf("%s %d", num, &type2);

		if (num[0] == '0') {
			printf("0\n");
			continue;
		}

		trans_type2(type2, trans_num(type1, num));
	}
	return;
}

int main(void) {
	solution();
	return 0;
}
