#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void solution(void) {
    int n;

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        int num = 1;
        for (int j = 0; j <2*n - 2 * i; ++j)
            printf(" ");
        for (int j = 0; j < i; ++j)
            printf("%d ", num++);
        printf("\n");

    }
    return;
}

int main(void) {
    solution();
    return 0;
}