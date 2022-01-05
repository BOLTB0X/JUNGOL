#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pane[101][101];

//변 체크
int count_leg(int y, int x) {
	int cnt = 0;
	if (pane[y + 1][x] == 0)
		cnt++;
	if (pane[y][x + 1] == 0)
		cnt++;
	if (pane[y - 1][x] == 0)
		cnt++;
	if (pane[y][x - 1] == 0)
		cnt++;

	return cnt;
}

void solution(void) {
	int n;
	scanf("%d", &n);

	//초기화
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			pane[i][j] = 0;
		}
	}

	while (n--) {
		int y, x;
		scanf(" %d %d", &y, &x);

		for (int i = y; i < y + 10; ++i) {
			for (int j = x; j < x + 10; ++j) 
				pane[i][j] = 1;
		}
	}

	int area = 0;
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (pane[i][j] == 1)
				area += count_leg(i, j);
		}
	}

	printf("%d\n", area);
	return;
}

int main(void) {
	solution();

	return 0;
}