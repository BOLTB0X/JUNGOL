#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void solution(void) {
    int n;

    scanf("%d", &n);

    int num = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j < i+1; ++j)
            printf("  ");
        for (int j = i; j <= n; ++j)
            printf("%d ", num++);
        printf("\n");
    }
    return;
}

int main(void) {
    solution();
    return 0;
}