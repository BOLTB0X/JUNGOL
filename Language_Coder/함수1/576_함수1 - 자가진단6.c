#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int get_val(int v1, int v2, char ch) {
	int res = 0;
	if (ch == '+')
		return v1 + v2;
	else if (ch == '-')
		return v1 - v2;
	else if (ch == '*')
		return v1 * v2;
	else if (ch == '/')
		return v1 / v2;
	else
		return 0;
}

int main(void) {
	int a, b;
	char ch;
	scanf("%d %c %d", &a, &ch, &b);

	printf("%d %c %d = %d\n", a, ch, b ,get_val(a, b, ch));

	return 0;
}