#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	double arr[6] = { 85.6, 79.5, 83.1, 80.0, 78.2, 75.0 };

	int a, b;
	scanf("%d %d", &a, &b);
	printf("%.1lf", arr[a - 1] + arr[b - 1]);

	return 0;
}