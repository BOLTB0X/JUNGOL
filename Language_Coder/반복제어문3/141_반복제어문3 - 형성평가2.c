#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void solution(void) {
    int n, i;

    scanf("%d", &n);

    for (int i =1; i <= 100; ++i) {
        int val = n * i;

        if (val >= 100) 
            break;
        printf("%d ", val);
        if (val % 10 == 0)
            break;
    }
    return;
}

int main(void) {
    solution();
    return 0;
}