#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a_h, a_w, b_h, b_w;
	scanf("%d %d", &a_h, &a_w);
	scanf("%d %d", &b_h, &b_w);
	printf("%d\n", a_h > b_h && a_w > b_w);

	return 0;
}