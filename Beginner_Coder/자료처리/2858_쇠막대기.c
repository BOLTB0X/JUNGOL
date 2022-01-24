#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void solution(void) {
	char stick[100001] = { 0, };
	int open_cnt = 0, result = 0;
	int flag = 0;

	scanf("%s", stick);

	for (int i = 0; i < strlen(stick); ++i) {
		if (stick[i] == '(') {
			open_cnt++;
			flag = 0;
		}
		else if (stick[i] == ')' && flag == 0) {
			result += --open_cnt;
			flag = 1;
		}
		else if (stick[i] == ')' && flag == 1) {
			result++;
			open_cnt--;
		}
	}
	printf("%d", result);
	return;
}

int main(void) {
	solution();
	return 0;
}
