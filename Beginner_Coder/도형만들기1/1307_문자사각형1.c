#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char pane[101][101];

void solution(void) {
	int n;

	scanf("%d", &n);
	
	int cur = 65;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = n - 1; j >= 0; --j) {
			pane[j][i] = (char)cur++;
			if (cur > 90)
				cur = 65;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			printf("%c ", pane[i][j]);
		printf("\n");
	}

	return;
}

int main(void) {
	solution();
	return 0;
}