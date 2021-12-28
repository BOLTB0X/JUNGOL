#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int num1;
	int num2;
} pair;

pair get_vals(int v1, int v2) {
	pair p;
	if (v1 > v2) {
		p.num1 = v1 / 2;
		p.num2 = v2 * 2;
	}
	else {
		p.num2 = v2 / 2;
		p.num1 = v1 * 2;
	}

	return p;
}

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);

	pair p = get_vals(a, b);
	printf("%d %d\n", p.num1, p.num2);

	return 0;
}