#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void solution(void) {
	char stick[100001];
	int open_cnt = 0, result = 0, cmp = 0;
	scanf("%s", stick);

	for (int i = 0; i < strlen(stick); ++i) {
		if (stick[i] == '(') {
			open_cnt++;
			cmp = 1;
		}

		else if (stick[i] == ')' && cmp == 1) {
			result += --open_cnt;
			cmp++;
		}
		
		else if (stick[i] == ')' && cmp != 1) {
			open_cnt--;
			result++;
			cmp++;
		}
	}

	printf("%d", result);
	return;
}

int main(void) {
	solution();
	return 0;
}