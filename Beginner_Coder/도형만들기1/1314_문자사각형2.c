#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char pane[101][101];

void solution(void) {
	int n;
	scanf("%d", &n);
	int alp = 65;

	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; ++j) {
				pane[j][i] = (char)alp++;
				if (alp > 90)
					alp = 65;
			}

		}
		else {
			for (int j = n - 1; j >= 0; --j) {
				pane[j][i] = (char)alp++;
				if (alp > 90)
					alp = 65;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) 
			printf("%c ", pane[i][j]);
		printf("\n");
	}
}

int main(void) {
	solution();
	return 0;
}