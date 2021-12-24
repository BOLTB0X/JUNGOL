#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char pane[210][210];
const int dy[5] = { 0,1,1,-1,-1 };
const int dx[5] = { 0,-1,1,1,-1 };


void fill_shape(int n) {	
	int len = n;
	char alp = 'A';

	for (int i = 1; i <= n; ++i) {
		int cy = i, cx = n;
		for (int dir = 1; dir <= 4; ++dir) {
			for (int j = 1; j < len; ++j) {
				pane[cy][cx] = alp++;
				if (alp > 'Z')
					alp = 'A';
				cy = cy + dy[dir];
				cx = cx + dx[dir];
			}
		}
		len--;
	}

	pane[n][n] = alp;
	
	return;
}

void print_shape(int n) {
	int left = n, right = n;
	for (int i = 1; i <= 2 * n - 1; ++i) {
		for (int j = 1; j < left; ++j) 
			printf("  ");
		for (int j = left; j <= right; ++j)
			printf("%c ", pane[i][j]);
		if (i < n)
			left--, right++;
		else
			left++, right--;
		printf("\n");
	}
	return;
}

void solution(void) {
	int n;
	scanf("%d", &n);

	fill_shape(n);
	print_shape(n);
}

int main(void) {
	solution();
	return 0;
}