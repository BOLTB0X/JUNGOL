#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define one 1
#define two 2
#define three 3

void solution(void) {
    printf("%d + %d = %d\n", one, one, one + one);
    printf("%d + %d = %d\n", one, two, one + two);
    printf("%d + %d = %d\n", one, three, one + three);
    printf("%d + %d = %d\n", two, one, two + one);
    printf("%d + %d = %d\n", two, two, two + two);
    printf("%d + %d = %d\n", two, three, two + three);
    printf("%d + %d = %d\n", three, one, three + one);
    printf("%d + %d = %d\n", three, two, three + two);
    printf("%d + %d = %d\n", three, three, three + three);

    return;
}

int main(void) {
	solution();
	return 0;
}