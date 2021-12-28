#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_val(int a, int b) {
	if (b == 0)
		return 1;

	int res = 1;
	for (int i = 0; i < b; ++i)
		res *= a;
	return res;
}

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d\n", get_val(a, b));

	return 0;
}