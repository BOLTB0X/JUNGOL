#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void solution(void) {
    int n;

    scanf("%d", &n);

    int num = 0;
    char alp = 'A';
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n - i; ++j)
            printf("%c ", alp++);
        for (int j = 0; j < i - 1; ++j)
            printf("%d ", num++);
        printf("\n");
    }
    return;
}

int main(void) {
    solution();
    return 0;
}