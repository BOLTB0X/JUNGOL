#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//substr 정의
char* substr(char* str, int start_idx, int cnt) {
	char* tmp = malloc(sizeof(char) * cnt + 1);

	strncpy(tmp, str + start_idx, cnt);
	tmp[cnt] = '\0';
	return tmp;
}

void solution(void) {
	char str[101] = { '\0', };
	int idx;

	scanf("%s", str);

	while (strlen(str) > 1) {
		char* tmp = malloc(sizeof(char) * strlen(str) + 1);
		
		scanf("%d", &idx);

		if (idx > strlen(str)) {
			tmp = substr(str, 0, strlen(str) - 1);
			strcpy(str, tmp);

			printf("%s\n", str);
		}

		else {
			tmp = substr(str, 0, idx - 1);
			strcat(tmp, substr(str, idx, strlen(str)));
			strcpy(str, tmp);
			printf("%s\n", str);
		}
	}
}

int main(void) {
	solution();

	return 0;
}
