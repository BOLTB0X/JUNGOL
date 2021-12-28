#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define max(a,b) (a > b ? a : b)

int get_max(int a, int b, int c) {
	if (a > b) {
		if (a > c)
			return a;
		else
			return c;
	}

	else {
		if (b > c)
			return b;
		else
			return c;
	}

	//return max(max(a,b),c);
}

int main(void) {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	printf("%d\n", get_max(a, b, c));

	return 0;
}