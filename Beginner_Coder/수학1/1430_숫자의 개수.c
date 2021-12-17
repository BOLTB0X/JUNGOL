#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // sprintf
#include <string.h> //strlen

void solution(void) {
	int a, b, c;
	char str[1001];
	scanf("%d %d %d", &a, &b, &c);

	//문자열 변환
	sprintf(str," %d", a * b * c);

	for (int i = 0; i <= 9; ++i) {
		int cnt = 0;
		for (int j = 0; j < strlen(str); ++j) {
			if (i == str[j] - '0')
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return;
}

int main(void) {
	solution();
	return 0;
}
