#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b;

	scanf("%d %d", &a, &b);

	//출력을 int로 함

	printf("%d %.2lf\n", (int)a / b, (float)a / (int)b);
	return 0;
}