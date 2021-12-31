#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pane[101][101];

void fill_pane(int n, int num , int x, int y) {
    if (n * n < num)
        return;

    if (x < 1)
        x = n;
    if (y < 1)
        y = n;
    pane[x][y] = num;

    if (num % n == 0)
        fill_pane(n, num + 1, x + 1, y);
    else
        fill_pane(n, num + 1, x - 1, y - 1);
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

    fill_pane(n, 1, 1, n / 2 + 1);
    print_pane(n);

    return;
}

int main(void) {
    solution();

    return 0;
}