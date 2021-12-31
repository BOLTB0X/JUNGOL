#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pane[101][101];

void fill_pane(int n) {
    int x = 1; // 행 - 처음에는 1
    int y = n / 2 + 1; // 열 - 초기값 중앙

    int end = n * n; // 배열에 채울 마지막 값

    for (int i = 1; i <= end; i++) {  // 배열에 채울 값 1부터 end까지
        pane[x][y] = i; // i를 배열의 현재 위치에 넣는다.
        if (i % n == 0) 
            x++;  // 만약 현재의 수가 n의 배수이면 아래로 이동
        else {
            x--, y--; // 왼쪽 위로 이동
            if (x < 1) 
                x = n; // x가 0이면 n으로
            if (y < 1) 
                y = n; // y가 0이면 n으로
        }
    }

    return;
}

void print_pane(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) 
            printf("%d ", pane[i][j]);
        printf("\n");
    }

    return;
}

void solution(void) {
	int n;
	scanf("%d", &n);

	fill_pane(n);
    print_pane(n);

    return;
}

int main(void) {
	solution();

	return 0;
}