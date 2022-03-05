#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//10진법 변환
long long trans_dec(int type1, char* number) {
	long long tot = 0;
	long long i, j;
	
	for (i = strlen(number) - 1, j = 1; i >= 0; --i, j *= type1) {
		if (number[i] >= 'A') 
			number[i] = '9' + (number[i] - 'A') + 1;
		tot += j * (number[i] - '0');
	}

	return tot;
}

//10진법 - > type2
void trans_type2(int type2, long long dec) {
	char res[1001];
	long long idx = 0;

	while (dec > 0) {
		int mod = dec % type2;

		if (mod > 9) //10진법을 넘어가면
			res[idx++] = mod - 10 + 'A';
		else
			res[idx++] = mod + '0';

		dec /= type2;
	}

	res[idx] = '\0';

	for (long long i = strlen(res) - 1; i >= 0; --i)
		printf("%c", res[i]);
	printf("\n");

	return;
}

void solution(void) {
	int type1, type2;
	char number[1000001];

	while (1) {
		scanf("%d", &type1);

		if (type1 == 0)
			break;
		scanf("%s %d", number, &type2);

		if (number[0] == '0') {
			printf("0\n");
			continue;
		}

		trans_type2(type2, trans_dec(type1, number));
	}
}

int main(void) {
	solution();
	return 0;
}
