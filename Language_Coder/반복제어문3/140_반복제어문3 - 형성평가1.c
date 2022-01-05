#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void solution(void) {
    int n, i;
    int tot = 0;
    for (i = 0; i < 20; i++) {
        scanf("%d", &n);
        tot += n;
        if (n == 0)
            break;
    }
    printf("%d %d", tot, tot / i);
	return;
}

int main(void) {
	solution();
	return 0;
}