#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void solution(void) {
    int n;

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j)
            printf("# ");
        printf("\n");
    }
    for (int i = 1; i <= n - 1; ++i) {
        for (int j = 0; j < i; ++j)
            printf("  ");
        for (int j = n - 1; j >= i; --j)
            printf("# ");
        printf("\n");
    }
    return;
}

int main(void) {
    solution();
    return 0;
}